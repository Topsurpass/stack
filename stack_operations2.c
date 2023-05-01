#include "monty.h"

/**
 * do_nothing - do nothing to the stack
 * @head: the pointer to the top of the stack
 * @line_number: the line where error occured
 *
 * Return: nothing
 */
void do_nothing(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}
/**
 * print_char - Print the character equivalent of the value at the
 * top of the stack
 * @head: pointer to the top of the stack
 * @line_number: the line number where the error occured
 *
 * Return: nothing
 */

void print_char(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL)
		stack_error(line_number, "can't pchar, stack empty");
	if ((*head)->n > 127 || (*head)->n < 0)
		stack_error(line_number, "can't pchar, value out of range");
	printf("%c\n",(*head)->n);
}
/**
 * print_str - print the string starting at the top of the stack
 * @head: the pointer to the head of the stack
 * @line_number: the line where error occured
 *
 * Return: noothing
 */
void print_str(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	temp = *head;
	if (*head == NULL)
		printf("\n");
	while (temp != NULL && temp->n > 0 && temp->n < 128)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
	(void) line_number;
}
/**
 * rotl_stack - rotates the stack to the top
 * @line_number: the line where error occur
 * @head: the pointer to the top of the stack
 *
 * Return: nothing
 */
void rotl_stack(stack_t **head, unsigned int line_number)
{
	stack_t *holder, *temp, *last;

	if (*head == NULL || (*head)->next == NULL)
		return;

	holder = (*head)->next;
	temp = last = *head;

	/* if more than 2 elements in stack */
	if (holder->next != NULL)
	{
		(*head)->next = holder->next;
		(*head)->next->prev = *head;
		holder->prev = NULL;
		holder->next = (*head)->next;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = last;
		last->next = NULL;
		last->prev = temp;
	}
	else
	{
		holder->prev->prev = holder;
		holder->prev->next = NULL;
		holder->prev = NULL;
		holder->next = *head;
	}
	(*head) = holder;
	(void) line_number;
}
/**
 * rotr_stack - rotates the stack to the bottom
 * @line_number: the line where error occur
 * @head: the pointer to the top of the stack
 *
 * Return: nothing
 */
void rotr_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}
