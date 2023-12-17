#include "monty.h"

/**
 * monty_stack - Sets _flag to stack
 * @stack: Pointer to stack list
 * @line_number: Line opcode occurs on
 */
void monty_stack(__attribute__ ((unused)) stack_t **stack,
	    __attribute__ ((unused)) unsigned int line_number)
{
	_flag = 0;
}

/**
 * monty_queue - Sets _flag to queue.
 * @stack: Pointer to stack list.
 * @line_number: Line opcode occurs on.
 */
void monty_queue(__attribute__ ((unused))stack_t **stack,
	    __attribute__ ((unused))unsigned int line_number)
{
	_flag = 1;
}

/**
 * error_exit - Frees the stack and exits due to erro.
 * @stack: Pointer to the head of the stack.
 *
 */
void error_exit(stack_t **stack)
{
	if (*stack)
		free_list(*stack);
	exit(EXIT_FAILURE);
}

/**
 * is_number - Checks if a string is a number.
 * @str: String to be cheked.
 *
 * Return: Returns 1 if string is a number, 0 otherwise.
 */
int is_number(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
