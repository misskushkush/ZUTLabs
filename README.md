# ZUTLabs
This is first year C/C++ laboratories from Zachodniopomosrki Uniwersytet Technologiczny
In the first half of the year we learned the basics of C language.
While the second half is still in progress. 
To understand what I learned in first half here is the task to the final program (Lab5).

Program requirements
1. The program should be multi-file: consist of header files *.h with declarations and
*.c files with definitions.
2. The program should define and demonstrate the use of the char* type (string.h library) and
own types (using structures, struct)
3. The program should demonstrate the ability to read data from files and theirs
saving.
4. The program should demonstrate communication between objects of its own types (e.g. definitions
eigentypes are to contain addresses to objects of other eigentypes)
5. Each own type is to be packed with a set of maximally independent functions from others
custom types.
6. The program should demonstrate the ability to manage heap memory over time
execution (related to the use of, for example, the malloc function):
a) It should dynamically handle arrays of objects (struct A*) and arrays of pointers to
objects of their own types (struct A**) and a two-dimensional array of pointers (struct A***).
b) Every program should have void or bool functions to manage memory in
runtime such as: create an array of objects of your own types, delete an array of objects
custom, add an object to the object array of custom types, remove the object to the object array
custom types, and a similar set of functions for handling pointers to objects of custom types.
7. The program should demonstrate the ability to use the technique of creating code that works
consists of many maximally independent files, which involves the use of data (including types
eigenvalues) and static functions.
8. The arguments of all functions should be protected with const od
accidental changes (protect both values and address values).
9. The functionality of the project is to be focused more on processing
information, and not only its reading and saving data.

C language syntax
Mandatory set of instructions (which results from the point. Requirements for the program, lectures and
accompanying examples) should include:
for, while, switch-case, if (>, <, &&, ||, etc), break, continue, const, static, scanf, puts, printf,
text handling with string.h (e.g. strcpy , strcat , strcmp), FILE, fopen, fclose, fprintf, feof,
stdin, stdout, fwrite, malloc, struct, enum.
