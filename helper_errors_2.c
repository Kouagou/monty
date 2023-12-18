#include "monty.h"

/**
 * err_pop - Prints pop error messages for empty stacks.
 * @line_number: Line number in script where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int err_pop(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}


/**
 * err_print - Prints pint error messages for empty stacks.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int err_print(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}


/**
 * err_short_stack - Prints monty math function error messages
 *                     for stacks/queues smaller than two nodes.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * @op: Operation where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int err_short_stack(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}


/**
 * err_div - Prints division error messages for division by 0.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int err_div(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}


/**
 * err_pchar - Prints pchar error messages for empty stacks
 *               empty stacks and non-character values.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * @message: The corresponding error message to print.
 *
 * Return: (EXIT_FAILURE) always.
 */
int err_pchar(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}

