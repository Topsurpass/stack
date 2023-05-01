#include "monty.h"

/**
 * run_monty - read each line from file and run the monty commands
 * @file: the file to read monty code from
 * @opcode: the push argument holder
 *
 * Return: noothing
 */

char *op_toks;
int CHECK = STACK; /* make stack the default state */
void run_monty(FILE *file)
{
	char *buf_line = NULL, *token;
	size_t len = 0;
	ssize_t nread;
	unsigned int line = 1;
	stack_t *head = NULL;

	while ((nread = getline(&buf_line, &len, file)) != -1) /* read each line till \n is reached */
	{
		token = strtok(buf_line, DELIM);
		if ((token != NULL && token[0] == '#') || token == NULL) /*skip comment but count the line*/
		{
			line++;
			continue;
		}
		else if (strcmp(token, "queue") == 0)
		{
			CHECK = QUEUE;
			line++;
			continue;
		}
		else if (strcmp(token, "stack") == 0)
		{
			CHECK = STACK;
			line++;
			continue;
		}
		else
		{
			while (token != NULL)
			{
				if (get_op_code_func(token) != NULL) /* check if the fxn for the opcode is not null */
				{
					if (strcmp(token, "push") == 0)
					{
						op_toks = strtok(NULL, DELIM); /* hold next token after push */
						if (check_4_alph(op_toks) == -1) /* check if the token contains alphabets */
						{
							stack_error(line, "usage: push integer");
							break;
						}
					}
					get_op_code_func(token)(&head, line); /* pass d next token if push otherwise only the opcode */
				}
				else
				{
					free_list(&head);
					fprintf(stderr, "L%d: unknown instruction %s\n", line, token);
					exit(EXIT_FAILURE);
				}
				token = strtok(NULL, DELIM);
			}
		}
		line++;
	}
	free(buf_line);
	free(head);
}
