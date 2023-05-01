#ifndef _MONTY_
#define _MONTY_

#define DELIM "\n\t\a\r ;:"
#define STACK 0
#define QUEUE 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char *op_toks;
extern int CHECK;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* The doubly linked list functions */
int add_node_to_stack(stack_t **head, int n);
int add_node_to_queue(stack_t **head, int n);
void del_node_end(stack_t **head);
void print_all_node(stack_t **head);
void free_list(stack_t **head);

/* The stack functions */
void push_val(stack_t **head, unsigned int line_number);
void pall_stack(stack_t **head, unsigned int line_number);
void pint_stack(stack_t **head, unsigned int line_number);
void pop_stack(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void do_nothing(stack_t **head, unsigned int line_number);
void print_char(stack_t **head, unsigned int line_number);
void print_str(stack_t **head, unsigned int line_number);
void rotl_stack(stack_t **head, unsigned int line_number);
void rotr_stack(stack_t **head, unsigned int line_number);
/*void queue_val(stack_t **head, unsigned int line_number);*/

/* The stack operations */
void add_stack(stack_t **head, unsigned int line_number);
void sub_stack(stack_t **head, unsigned int line_number);
void div_stack(stack_t **head, unsigned int line_number);
void mul_stack(stack_t **head, unsigned int line_number);
void mod_stack(stack_t **head, unsigned int line_number);


/* get function based on opcode */
void (*get_op_code_func(char *tok))(stack_t **stack, unsigned int line_number);

/* get line declaration */
size_t getline(char **lineptr, size_t *n, FILE *stream);

/* Set errors */
int usage_error(void);
int malloc_error(void);
int fileopen_error(char *filename);
int unknown_opcodes_error(char *opcode, unsigned int line_number);
int stack_error(unsigned int line_number, char *error_msg);

/* utilities */
int check_4_alph(char *str);
/*int chk_stk_que_com(char *token, unsigned int line);*/

/* run monty */
void run_monty(FILE *file);

#endif
