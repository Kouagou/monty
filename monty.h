#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

extern int _flag;

				/*--- STRUCT DEFINITIONS ---*/
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
 * struct instruction_s - opcoode and its function
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

			/* HELPERS_FUNC.C */
typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
char *parse_line(char *line);
instruct_func get_opcode_func(char *str);
void read_file(char *filename, stack_t **stack);

			/* OPCODE_FUNC_1.C */
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);

			/* OPCODE_FUNC_2.C */
void monty_add(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);

			/* OPCODE_FUNC_3.C */
void monty_mod(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);
void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);

			/* OPCODE_FUNC_4.C */
void monty_queue(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void error_exit(stack_t **stack);
int is_number(char *str);

			/* OPCODE_FUNC_5.C */
stack_t *add_node(stack_t **head, const int n);
stack_t *add_node_at_end(stack_t **head, const int n);
int delete_node_at_index(stack_t **head, unsigned int index);
void free_list(stack_t *head);


#endif
