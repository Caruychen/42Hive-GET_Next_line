cp ../src/get_next_line.h ./includes/

echo "Compiling..."
make -s
make -s fclean
make -s clean
make -s re

echo "Running test suite"
find text_files/ -name '*.txt' -type f | sed 's/text_files\/\///g' | sed 's/.txt//g' > file_names
while read f; do
	./test "$f".txt > text_files/"$f".user
	diff text_files/"$f".txt text_files/"$f".user
done <file_names
make fclean
