GREEN="\033[0;32m"
RED="\033[1;31m"
YELLOW="\033[1;33m"
NC="\033[0m"

COMPARE_FILES(){
	arg1=$1
	arg2=$2
	if [[ -n "$(cmp $arg1 $arg2)" ]]
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

LOOP_TEST_FILES(){
	arg=$1
	while read f; do
		printf "Testing $f from stdout:	"
		cat text_files/$arg/"$f".txt | ./test > text_files/$arg/"$f".std
		COMPARE_FILES text_files/$arg/"$f".txt text_files/$arg/"$f".std
	done <file_names.txt
	while read f; do
		printf "Testing $f from file:	"
		./test text_files/$arg/"$f".txt
		COMPARE_FILES text_files/$arg/"$f".txt text_files/$arg/"$f".output
	done <file_names.txt
}

echo "Setting BUFF_SIZE to 8"
cp ../includes/get_next_line.h ./includes/
sed -i.bu 's/BUFF_SIZE .*/BUFF_SIZE 8/g' ./includes/get_next_line.h
rm ./includes/get_next_line.h.bu

echo "Compiling..."
make -s

echo "Running test suite...\n"
echo "${YELLOW}--- Checking Basic tests ---${NC}"
GET_INPUTS basic
LOOP_TEST_FILES basic

echo "${YELLOW}--- Checking Middle tests ---${NC}"
GET_INPUTS middle
LOOP_TEST_FILES middle

echo "${YELLOW}--- Checking Advanced tests ---${NC}"
GET_INPUTS advanced
LOOP_TEST_FILES advanced
make fclean
