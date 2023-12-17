#include "monty.h"
int _flag = 0;
/**
 * main - driver function for monty program
 * @argc: int num of arguments
 * @argv: opcode file
 * Return: 0
 */
int main(int argc, char **argv)
{
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		error_exit(&stack);
	}
	read_file(argv[1], &stack);
	free_list(stack);
	return (0);
}
