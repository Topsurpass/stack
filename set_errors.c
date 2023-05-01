#include "monty.h"

/**
 * usage_error - Prints error indicating how to run the program
 * from command line
 *
 * Return: (EXIT_FAILURE) always.
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Prints error if memory cannot be allocated.
 *
 * Return: (EXIT_FAILURE) always.
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - Prints error if filename cannot be open.
 * @filename: Name of file that failed to open
 *
 * Return: (EXIT_FAILURE) always.
 */
int fileopen_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - Prints error if bytecode command is unknown.
 * @opcode: The unknown opcode.
 * @line_number: Line number in Monty bytecodes file where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int unknown_opcode_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}
/**
 * stack_error - print error if stack contains less than 2 elements or error
 * @line_number: The line number where the error occoured
 * @error_msg: the error message to be printed
 *
 * Return: nothing
 */
int stack_error(unsigned int line_number, char *error_msg)
{
	fprintf(stderr, "L%u: %s\n", line_number, error_msg);
	exit(EXIT_FAILURE);
}
