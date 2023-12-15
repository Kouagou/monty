#include "monty.h"
/**
 * monty_push - Push int to a stack.
 * @stack: Linked lists for monty stack.
 * @line_number: Number of line opcode occurs on.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));
	char *arg;
	int push_arg = 0;

	if (!new)
	{
		printf("Error: malloc failed\n");
		error_exit(stack);
	}

	arg = strtok(NULL, "\n ");
	if (is_number(arg) == 1 && arg != NULL)
	{
		push_arg = atoi(arg);
	}
	else
	{
		printf("L%d: usage: push integer\n", line_number);
		error_exit(stack);
	}

	if (_flag == 1)
	{
		add_node_at_end(stack, push_arg);
	}

	if (_flag == 0)
	{
		add_node(stack, push_arg);
	}

}
/**
 * monty_pall - Print all function.
 * @stack: Pointer to linked list stack.
 * @line_number: Number of line opcode occurs on.
 */
void monty_pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner = *stack;

	while (runner != NULL)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
}
/**
 * monty_pint - Print int a top of stack.
 * @stack: Pointer to linked list stack.
 * @line_number: Number of line opcode occurs on.
 *
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;

	if (runner == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		error_exit(stack);
	}
	printf("%d\n", runner->n);
}
/**
 * monty_swap - Swap top of stack and second top of stack.
 * @stack: Pointer to linked list stack.
 * @line_number: Number of line opcode occurs on.
 *
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;
	int tmp;

	if (runner == NULL || runner->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		error_exit(stack);
	}
	tmp = runner->n;
	runner->n = runner->next->n;
	runner->next->n = tmp;
}
/**
 * monty_pop - Delete item at top of stack.
 * @stack: Pointer to linked list stack.
 * @line_number: Number of line opcode occurs on.
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		error_exit(stack);
	}
	delete_node_at_index(stack, 0);
}
