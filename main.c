#include "monty.h"

/**
 * main - the entrance to our program
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: 0 (end of our program)
 */

int main(int argc, char **argv)
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	run_monty(file); /* run monty based on opcodes found in file */
	fclose(file);
	return (0);
}
