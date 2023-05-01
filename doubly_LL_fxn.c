#include "monty.h"

/**
 * add_node_to_stack - add node at the end of doubly linked list
 * @head: the head node
 * @n: the integer data
 *
 * Return: 0 if successful and -1 if failed
 */
int add_node_to_stack(stack_t **head, int n)
{
	stack_t *new, *tmp;

	if (head == NULL)
		return (-1);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		return (-1);
	}
	new->n = n;

	/* if linked list is empty */
	if (*head == NULL)
	{
		*head = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		if (CHECK == STACK)
		{
			new->next = *head;
			(*head)->prev = new;
			*head = new;
		}
		else if (CHECK == QUEUE)
		{
			tmp = *head;
			while (tmp->next)
				tmp = tmp->next;
			new->prev = tmp;
			new->next = NULL;
			tmp->next = new;
		}
	}
	return (0);
}

/**
 * del_node_end - Delete node at the end of doubly LL
 * @head: pointer to the end of the doubly LL
 *
 * Return: nothing
 */
void del_node_end(stack_t **head)
{
	stack_t *del;

	/*if no doubly linked list or if the doubly linked list is empty */
	if (head == NULL || *head == NULL)
		return;
	 /*if there's just one node in the doubly linked list*/
	del = *head;
	if ((*head)->next == NULL)
	{
		*head = NULL;
		free(del);
	}
	else
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(del);
	}
}
/**
 * print_all_node - print all the node in doubly linked list
 * from tail node to head
 * @head: the pointer to the head node
 *
 * Return: nothing
 */

void print_all_node(stack_t **head)
{
	stack_t *traverse;

	if (*head == NULL || head == NULL)
		return;
	traverse = *head;

	while (traverse != NULL)
	{
		printf("%d\n", traverse->n);
		traverse = traverse->next;
	}

}

/**
 * free_list - free doubly linked list
 * @head: pointer to the head node
 *
 * Return: nothing
 */
void free_list(stack_t **head)
{
	if (head == NULL || *head == NULL)
		return;

	while (*head != NULL && (*head)->next != NULL)
	{
		*head = (*head)->next;
		free((*head)->prev);
	}
	free(*head);
}
