#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define QUEUE 1
#define STACK 0
#define DELIMS " \n\t\a\b"


/* GLOBAL OPCODE TOKENS */
extern char **op_toks;


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

/* HELPER_ERROR_1.C */
int err_malloc(void);
int err_unknown(char *opcode, unsigned int line_number);
int err_no_integer(unsigned int line_number);
void err_set_op_tok(int error_code);

/* HELPER_ERROR_2.C */
int err_pop(unsigned int line_number);
int err_print(unsigned int line_number);
int err_short_stack(unsigned int line_number, char *op);
int err_div(unsigned int line_number);
int err_pchar(unsigned int line_number, char *message);

/* PRIMARY INTERPRETER FUNCTIONS */
void free_list(stack_t **stack);
int init_list(stack_t **stack);
int check_mode_list(stack_t *stack);
void free_tokens(void);
unsigned int token_arr_len(void);
int run_monty(FILE *script_fd);


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


/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strtow(char *str, char *delims);
char *get_int(int n);


#endif
