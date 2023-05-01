#include "monty.h"

/**
 * check_4_alph - check if string contains alphabets
 * @str: the string to check
 *
 * Return: -1 if true and 0 if false
 */
int check_4_alph(char *str)
{
	int i;
	if (str == NULL || *str == '\0')
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
	}
	return (0);
}
/* chk_stk_que_com - check if data is in stack or queue and if
 * opcode start with # i.e comment
 * @line: line where error occured
 * @token: the opcode to check
 *
 * Return: nothing
 
 
int chk_stk_que_com(char *token, unsigned int line)
{
	if (token != NULL && token[0] == '#')  skip comment but count the line
	{
		line++;
		return (1);
	}
	if (strcmp(token, "queue") == 0)
	{
		CHECK = QUEUE;
		return (1);
	}
	if (strcmp(token, "stack") == 0)
	{
		CHECK = STACK;
		return (1);
	}
	return (0);
}
*/
