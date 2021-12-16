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
	  printf "${RED}NOT OK!${NC}"
	else
	  printf "${GREEN}OK!${NC}"
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
	arg1=$1
	arg2=$2
	nl=$3
	valgrind --log-file="vallog" ./test $nl text_files/$arg1/$arg2.txt
	cat vallog | grep -e 'definitely' -e 'indirectly' | sed 's/.*: //g' | sed 's/ .*//g' > leakcheck
	leaks=$(awk '{ sum += $1 } END { print sum }' leakcheck)
	printf " Leaks: $leaks"
	rm vallog
	rm leakcheck
}

LOOP_TEST_FILES(){
	arg=$1
	while read f; do
		printf "\nTesting $f from stdout:	"
		if [[ "$f" == *d4* || "$f" == *d5* || "$f" == *d6* ]]
		then
			nl=0
		else
			nl=1
		fi
		cat text_files/$arg/"$f".txt | ./test $nl > text_files/$arg/"$f".std
		COMPARE_FILES text_files/$arg/"$f".txt text_files/$arg/"$f".std
	done <file_names.txt
	while read f; do
		printf "\nTesting $f from file:	"
		if [[ "$f" == *d4* || "$f" == *d5* || "$f" == *d6* ]]
		then
			nl=0
		else
			nl=1
		fi
		./test $nl text_files/$arg/"$f".txt
		COMPARE_FILES text_files/$arg/"$f".txt text_files/$arg/"$f".output
		CHECK_LEAKS $arg $f $nl
	done <file_names.txt
}

echo "Setting BUFF_SIZE to 8"
cp ../includes/get_next_line.h ./includes/
sed -i.bu 's/BUFF_SIZE .*/BUFF_SIZE 8/g' ./includes/get_next_line.h
rm ./includes/get_next_line.h.bu

echo "Compiling..."
make -s

echo "Running test suite...\n"
echo "\n${YELLOW}--- Checking Basic tests ---${NC}"
GET_INPUTS basic
LOOP_TEST_FILES basic

echo "\n${YELLOW}--- Checking Middle tests ---${NC}"
GET_INPUTS middle
LOOP_TEST_FILES middle

echo "\n${YELLOW}--- Checking Advanced tests ---${NC}"
GET_INPUTS advanced
LOOP_TEST_FILES advanced

echo "\n${YELLOW}--- Checking Error  tests ---${NC}"
printf "Testing arbitrary fd = 42:	"
./test 2
res="$?"
if [[ "$res" -ne 0 ]]
then
  echo "${RED}NOT OK!${NC}"
else
  echo "${GREEN}OK!${NC}"
fi
make fclean
