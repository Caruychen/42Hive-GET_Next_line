#!/bin/zsh
GREEN="\033[0;32m"
RED="\033[1;31m"
YELLOW="\033[1;33m"
NC="\033[0m"

COMPARE_FILES(){
	arg1=$1
	arg2=$2
	result=$(diff $arg1 $arg2)
	if [[ -n "$result" ]]
	then
	  echo "${RED}NOT OK!${NC}"
	else
	  echo "${GREEN}OK!${NC}"
	fi
}

GET_INPUTS(){
	arg=$1
	find text_files/$arg -name $arg'*.txt' -type f | sed "s/text_files\/$arg\///g" | sed 's/.txt//g' > file_names.txt
}

NO_NEWLINE(){
	arg=$1
	if [[ "$arg" == *d4* || "$arg" == *d5* || "$arg" == *d6* ]]
	then
		return 1
	else
		return 0
	fi
}

CHECK_LEAKS(){
	eval valgrind --log-file="vallog" $1
	cat vallog | grep -e 'definitely' -e 'indirectly' | sed 's/.*: //g' | sed 's/ .*//g' > leakcheck
	leaks=`awk '{ sum += $1 } END { print sum }' leakcheck`
	echo " Leaks: $leaks"
	rm vallog
	rm leakcheck
}

LOOP_TEST_FILES(){
	arg=$1
	while read f; do
		echo -n "Testing $f from stdout:	"
		if [[ "$f" == *d4* || "$f" == *d5* || "$f" == *d6* ]]
		then
			nl=0
		else
			nl=1
		fi
		CMD="cat text_files/$arg/"$f".txt | ./test $nl > text_files/$arg/"$f".std"
		eval $CMD
		COMPARE_FILES text_files/$arg/"$f".txt text_files/$arg/"$f".std
	done <file_names.txt
	while read f; do
		echo -n "Testing $f from file:	"
		if [[ "$f" == *d4* || "$f" == *d5* || "$f" == *d6* ]]
		then
			nl=0
		else
			nl=1
		fi
		CMD="./test $nl text_files/$arg/"$f".txt"
		eval $CMD
		COMPARE_FILES text_files/$arg/"$f".txt text_files/$arg/"$f".output
	done <file_names.txt
}

cp ../includes/get_next_line.h ./includes/
sed -i.bu -e 's/BUFF_SIZE .*/BUFF_SIZE 256/g' \
	-e 's/include "libft\//include "/g' ./includes/get_next_line.h
rm ./includes/get_next_line.h.bu
rm -rf ./text_files/**/*.std ./text_files/**/*.output

echo "Compiling..."
make re -s

./test 4

echo "Running test suite...\n"
echo "${YELLOW}--- Checking Basic tests ---${NC}"
GET_INPUTS basic
LOOP_TEST_FILES basic

echo "\n${YELLOW}--- Checking Middle tests ---${NC}"
GET_INPUTS middle
LOOP_TEST_FILES middle

echo "\n${YELLOW}--- Checking Advanced tests ---${NC}"
GET_INPUTS advanced
LOOP_TEST_FILES advanced

echo "\n${YELLOW}--- Checking Error  tests ---${NC}"
echo -n "Testing arbitrary fd = 42:	"
CMD="./test 2"
eval $CMD
res="$?"
if [[ "$res" -ne 0 ]]
then
  echo "${RED}NOT OK!${NC}"
else
  echo "${GREEN}OK!${NC}"
fi

echo "\n${YELLOW}--- Checking Multi-file test ---${NC}"
echo "Testing three sample files...	"
CMD="./test 3"
eval $CMD
echo -n "File 1 diff: "
COMPARE_FILES text_files/bonus/multi1.txt text_files/bonus/multi1.output
echo -n "File 2 diff: "
COMPARE_FILES text_files/bonus/multi2.txt text_files/bonus/multi2.output
echo -n "File 3 diff: "
COMPARE_FILES text_files/bonus/multi3.txt text_files/bonus/multi3.output
echo ""
make fclean
