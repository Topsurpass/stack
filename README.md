# THE MONTY LANGUAGE

This is a modified version of my ALX Monty project. Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## REQUIREMENTS:

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=c89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* You allowed to use a maximum of one global variable
* No more than 5 functions per file
* You are allowed to use the C standard library
* The prototypes of all your functions should be included in your header file called monty.h
* Don’t forget to push your header file
* All your header files should be include guarded
* You are expected to do the tasks in the order shown in the project

## OPCODES IMPLEMENTED
By default, the monty is in the stack mode but it can be changed to queue depending on the user. Below are some of the few opcodes implemented:

* push - Push to the top of stack
* pall - Print the stack
* pint - Print all the values in stack from top of stack
* pop - Remove or delete last element of the stack
* swap - Swap the first 2 element of the stack
* add - Add the first 2 element of the stack
* sub - Subtract the first 2 element of the stack.
* div - Divide the first 2 element of the stack
* mul - Multiply the first 2 element of the stack
* mod - Get the remainder of the division between the first 2 element of the stack
* pchar - Print character
* pstr - Print string
* rotl - Rotate the stack to the left
* rotr - Rotate the stack to the right
* nop - Do nothing to the stack

# USAGE:
Step 1: Write your monty instructions in a file with .m extension.
 
vagrant@ubuntu$: cat -e bytecodes/00.m <br>
push 1<br>
push 2<br>
push 3<br>
pall<br>

Step 2: Now run monty and pass the file as an argument to it.

vagrant@ubuntu$: ./monty bytecodes/00.m <br>
3<br>
2<br>
1<br>

## COMPILATIONS AND OUTPUTS:
Your code will be compiled this way:

$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
Any output must be printed on stdout
Any error message must be printed on stderr

## LIMITATIONS
This code makes use of two extern variables, also, there are only few monty opcodes implemented.

## AUTHOR
Olowosuyi Temitope - temitopeabiodun685@gmail.com
