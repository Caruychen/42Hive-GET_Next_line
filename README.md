# 42Hive-GET_Next_line

The aim of this project was to code a function that returns a line ending with a new line, read from a file descriptor.

The return value can be 1, 0 or -1 depending on whether a line has been read, when the reading has been completed, or if an error has happened respectively.Calling get_next_line in a loop will then allow you to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.

This exercise allowed us to learn a new concept in C Programming: Static variables. These are variables that preserve their value even when they are outside of their scope. As such, a function that is called multiple times with static variable will remember its value each time it is called.

We also gain a deeper understanding of memory allocations, whether they happen on the heap or the stack, and also the manipulation and life-cycpe of a buffer.

For this project, I implemented a dynamic array for the libft library. The dynamic array is used as the buffer, which is pre-emptively expanded as needed when reading a file. This helped to substantially improve read speeds, and minimise the frequency of memory allocations.
