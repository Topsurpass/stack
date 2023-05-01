#include "monty.h"
/**
 * push_val - Push values to the top of stack
 * @head: the pointer to the end of stack
 * @line_number: the line number where error occured
 * @n: the integer to be added to stack
 *
 * Return: nothing
 */
void push_val(stack_t **head, unsigned int line_number)
{
	if (head == NULL)
		malloc_error();
	(void) line_number;
	add_node_to_stack(head, atoi(op_toks));	
}
/**
 * pall_stack - print all the values on the stack, from top
 * of the stack to bottom
 * @head: the pointer to the end of the stack
 * @line_number: the line number where error occured
 *
 * Return: nothing
 */

void pall_stack(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	print_all_node(head);
}

/**
 * pint_stack - print all the values on the stack, from
 * top of the stack
 * @head: the pointer to the end of the stack
 * @line_number: the line number where error occured
 *
 * Return: nothing
 */
void pint_stack(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || head == NULL)
		stack_error(line_number, "cant't pint, stack empty");
	printf("%d\n", (*head)->n);
}
/**
 * pop_stack - remove the top element from the stack
 * @head: the pointer to the top element of the stack
 * @line_number: the line number containing the error
 *
 * Return: nothing
 */
void pop_stack(stack_t **head, unsigned int line_number)
{
	/* if no doubly linked list or if the doubly linked list is empty */
	if (head == NULL || *head == NULL)
		stack_error(line_number, "cant't pop an empty stack");
	del_node_end(head);
}
/**
 * swap - swaps the top two elements of the stack
 * @line_number: the line where error occur
 * @head: the pointer to the top of the stack
 *
 * Return: nothing
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *holder;

	if (*head == NULL || (*head)->next == NULL)
		stack_error(line_number, "cant't swap, stack too short");
	holder = (*head)->next;
	/* if more than 2 elements in stack */
	if (holder->next != NULL)
	{
		(*head)->next = holder->next;
		(*head)->next->prev = *head;
	}
	else
	{
		holder->prev->prev = holder;
		holder->prev->next = NULL;
	}
	holder->prev = NULL;
	holder->next = *head;
	(*head) = holder;
}
