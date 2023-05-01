#include "monty.h"

/**
 * add_stack - add top 2 elements of the stack
 * @head: pointer to the top of the stack
 * @line_number: the line where error occured
 *
 * Return: nothing
 */
void add_stack(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
		stack_error(line_number, "cant't add, stack too short");

	(*head)->next->n += (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;

}
/**
 * sub_stack - subtracts the top element of the stack from the
 * second top element of the stack.
 * @head: the pointer to the top element of the stack
 * @line_number: The line number where error occur
 *
 * Return: nothing
 */
void sub_stack(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
		stack_error(line_number, "can't sub, stack too short");

	(*head)->next->n -= (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
/**
 * div_stack - divide the second top element of the stack by the
 * top element of the stack.
 * @head: the pointer to the top element of the stack
 * @line_number: The line number where error occur
 *
 * Return: nothing
 */
void div_stack(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
		stack_error(line_number, "can't div, stack too short");
	if ((*head)->n == 0)
		stack_error(line_number, "division by zero");

	(*head)->next->n /= (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
/**
 * mul_stack - multiply the second top element of the stack with the
 * top element of the stack.
 * @head: the pointer to the top element of the stack
 * @line_number: The line number where error occur
 *
 * Return: nothing
 */
void mul_stack(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
		stack_error(line_number, "can't mul, stack too short");

	(*head)->next->n *= (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
/**
 * mod_stack - compute rest of the division of the second top element
 * of the stack by the top element
 * @head: the pointer to the top element of the stack
 *
 * Return: nothing
 */
void mod_stack(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
		stack_error(line_number, "can't mod, stack too short");
	if ((*head)->n == 0)
		stack_error(line_number, "division by zero");

	(*head)->next->n %= (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
