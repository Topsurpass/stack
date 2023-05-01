#include "monty.h"

/**
 * get_op_code_func - compare opcodes and perform its corresponding function
 * @toks: the opcode to be compared
 *
 * Return: a function to pointer
 */
void (*get_op_code_func(char *tok))(stack_t **stack, unsigned int line_number)
{
	instruction_t op_arr[] = {
		{"pall", pall_stack},
		{"push", push_val},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{"swap", swap},
		{"add", add_stack},
		{"sub", sub_stack},
		{"div", div_stack},
		{"mul", mul_stack},
		{"mod", mod_stack},
		{"nop", do_nothing},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl_stack},
		{"rotr", rotr_stack},
		/*{"queue", queue_val},*/
		{NULL, NULL}
	};

	int i = 0;

	while (op_arr[i].opcode != NULL)
	{
		if (strcmp(tok, op_arr[i].opcode) == 0)
		{
			return (op_arr[i].f);
		}
		i++;
	}
	return (NULL);
}

