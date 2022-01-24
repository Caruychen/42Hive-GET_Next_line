# 42Hive-GET_Next_line

The aim of this project was to code a function that returns a line ending with a new line, read from a file descriptor.

The return value can be 1, 0 or -1 depending on whether a line has been read, when the reading has been completed, or if an error has happened respectively.Calling get_next_line in a loop will then allow you to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.

This exercise allowed us to learn a new concept in C Programming: Static variables. These are variables that preserve their value even when they are outside of their scope. As such, a function that is called multiple times with static variable will remember its value each time it is called.
