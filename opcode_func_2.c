#include "monty.h"


void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);


/**
 * monty_add - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		err_set_op_tok(err_short_stack(line_number, "add"));
		return;
	}


	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}


/**
 * monty_sub - Subtracts the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		err_set_op_tok(err_short_stack(line_number, "sub"));
		return;
	}


	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_number);
}


/**
 * monty_div - Divides the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		err_set_op_tok(err_short_stack(line_number, "div"));
		return;
	}


	if ((*stack)->next->n == 0)
	{
		err_set_op_tok(err_div(line_number));
		return;
	}


	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_number);
}


/**
 * monty_mul - Multiplies the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		err_set_op_tok(err_short_stack(line_number, "mul"));
		return;
	}


	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_number);
}


/**
 * monty_mod - Computes the modulus of the second value from the
 *             top of a stack_t linked list  by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		err_set_op_tok(err_short_stack(line_number, "mod"));
		return;
	}


	if ((*stack)->next->n == 0)
	{
		err_set_op_tok(err_div(line_number));
		return;
	}


	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}

