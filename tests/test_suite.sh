cp ../includes/get_next_line.h ./includes/
sed -i.bu 's/BUFF_SIZE .*/BUFF_SIZE 8/g' ./includes/get_next_line.h

echo "Compiling..."
make -s
rm ./includes/get_next_line.h.bu

echo "Running test suite"
find text_files/ -name '*.txt' -type f | sed 's/text_files\/\///g' | sed 's/.txt//g' > file_names.txt
echo "12345678" | ./test
while read f; do
	./test 1 text_files/"$f".txt text_files/"$f".user
	diff text_files/"$f".txt text_files/"$f".user
done <file_names.txt
make fclean
