# README

This is a program that performs either a string search or a sorting operation depending on the input. The program has two functions:

## Function 1: String search

This function searches for a given string (the "special word") within a set of input lines. The input lines are read from stdin until the end of input is reached (EOF). If the special word appears in a line, the entire line is printed to stdout.
To run this function, the user must provide two arguments to the program: the special word and the letter "a". For example:

> ./Ex3 cat a

## Function 2: Sorting

This function reads a list of integers from stdin and performs an insertion sort on the list. The sorted list is then printed to stdout, with each integer separated by a comma.
To run this function, the user must provide two arguments to the program: the special word and the letter "b". For example:

> ./Ex3 cat b

## Compiling and Running the Program

To compile the program, run the make command. This will create two executables: isort and txtfind.
To run the string search function, execute txtfind with the appropriate arguments. To run the sorting function, execute isort with the appropriate arguments.

## Additional Notes

    * The program has a maximum input size of 64000 characters.
    * The program expects the input to be formatted correctly. If the input is not formatted correctly, the program may produce unexpected results or crash.
    * The program does not handle error cases gracefully. If the program encounters an error, it may produce unexpected results or crash.
