#include "monty.h"
/**
 * monty_mod - Mod top of stack and second top of stack.
 * * @stack: Pointer to linked list stack.
 * @line_number: Number of line opcode occurs on.
 *
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mod, stack too short\n", line_number);
		error_exit(stack);
	}
	if ((*stack)->n == 0)
	{
		printf("L%d: division by zero\n", line_number);
		error_exit(stack);
	}
	(*stack)->next->n %= (*stack)->n;
	monty_pop(stack, line_number);
}

/**
 * monty_pchar - Prints the ASCII value of a number.
 * @stack: Pointer to the top of the stack.
 * @line_number: The index of the current line.
 *
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;
	int val;

	if (*stack == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line_number);
		error_exit(stack);
	}

	runner = *stack;
	val = runner->n;

	if (!isprint(val))
	{
		printf("L%d: can't pchar, value out of range\n", line_number);
		error_exit(stack);
	}

	putchar(val);
	putchar('\n');
}
/**
 * monty_pstr - Print string starting a top of stack.
 * @stack: Linked list for stack.
 * @line_number: Line number opcode occurs on.
 */
void monty_pstr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner = *stack;
	int val;

	while (runner != NULL)
	{
		val = runner->n;
		if (val == 0)
			break;
		if (!isprint(val))
		{
			break;
		}
		putchar(val);
		runner = runner->next;
	}
	putchar('\n');
}

/**
 * monty_rotl - Rotates the list left.
 * @stack: Pointer to the top of the stack.
 * @line_number: The index of the current line.
 *
 */
void monty_rotl(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner;
	int temp1, temp2;

	if (*stack == NULL)
		return;
	runner = *stack;
	while (runner->next)
		runner = runner->next;
	while (runner)
	{
		if (!runner->next)
		{
			temp1 = runner->n;
			runner->n = (*stack)->n;
		}
		else
		{
			temp2 = runner->n;
			runner->n = temp1;
			temp1 = temp2;
		}
		runner = runner->prev;
	}
}
/**
 * monty_rotr - Rotates the list right.
 * @stack: Pointer to the top of the stack.
 * @line_number: The index of the current line.
 *
 */
void monty_rotr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner1, *runner2;
	int temp1, temp2;

	if (*stack == NULL)
		return;

	runner1 = *stack;
	runner2 = *stack;
	while (runner1->next)
		runner1 = runner1->next;
	while (runner2)
	{
		if (runner2->prev == NULL)
		{
			temp1 = runner2->n;
			runner2->n = runner1->n;
		}
		else
		{
			temp2 = runner2->n;
			runner2->n = temp1;
			temp1 = temp2;
		}
		runner2 = runner2->next;

	}
}