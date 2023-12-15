#include "monty.h"
/**
 * monty_add - Adds top of stack and second top of stack.
 *
 * @stack: Pointer to linked list stack.
 * @line_number: Number of line opcode occurs on.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		error_exit(stack);
	}
	(*stack)->next->n += (*stack)->n;
	monty_pop(stack, line_number);
}

/**
 * monty_nop - Literally does nothing.
 * @stack: Pointer to the top of the stack.
 * @line_number: The index of the current line.
 *
 */
void monty_nop(__attribute__ ((unused))stack_t **stack,
	  __attribute__ ((unused))unsigned int line_number)
{
	;
}
/**
 * monty_sub - Subtracts top of stack and second top of stack.
 *
 * @stack: Pointer to linked list stack.
 * @line_number: Number of line opcode occurs on.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		error_exit(stack);
	}
	(*stack)->next->n -= (*stack)->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mul - Multiply top of stack and second top of stack.
 * @stack: Pointer to linked list stack.
 * @line_number: Number of line opcode occurs on.
 *
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		error_exit(stack);
	}
	(*stack)->next->n *= (*stack)->n;
	monty_pop(stack, line_number);
}

/**
 * monty_div - Divide top of stack and second top of stack.
 * @stack: Pointer to linked list stack.
 * @line_number: Number of line opcode occurs on.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		error_exit(stack);
	}
	if ((*stack)->n == 0)
	{
		printf("L%d: division by zero\n", line_number);
		error_exit(stack);
	}
	(*stack)->next->n /= (*stack)->n;
	monty_pop(stack, line_number);
}
