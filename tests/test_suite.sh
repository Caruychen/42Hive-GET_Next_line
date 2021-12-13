echo "Compiling..."
make -s
make -s fclean
make -s clean
make -s re

echo "Running test suite"
./test text1.txt
./test text2.txt
make fclean
