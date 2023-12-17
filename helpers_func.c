#include "monty.h"

/**
 * read_file - Reads a bytecode file and runs commands.
 * @filename: Pathname to file.
 * @stack: Pointer to the top of the stack.
 *
 */
void read_file(char *filename, stack_t **stack)
{
	char *buffer = NULL, *line;
	size_t i = 0;
	int line_count = 1, check, read;
	instruct_func s;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		error_exit(stack);
	}
	while ((read = getline(&buffer, &i, file)) != -1)
	{
		line = parse_line(buffer);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		s = get_opcode_func(line);
		if (s == NULL)
		{
			printf("L%d: unknown instruction %s\n", line_count, line);
			error_exit(stack);
		}
		s(stack, line_count);
		line_count++;
	}
	free(buffer);
	check = fclose(file);
	if (check == -1)
		exit(-1);
}

/**
 * parse_line - Parses a line for an opcode and arguments.
 * @line: The line to be parsed.
 *
 * Return: Returns the opcode or null on failure.
 */
char *parse_line(char *line)
{
	char *opcode = strtok(line, "\n ");

	if (opcode == NULL)
		return (NULL);
	return (opcode);
}

/**
 * get_opcode_func -  Checks opcode and returns the correct function.
 * @str: The opcode.
 *
 * Return: Returns a function, or NULL on failure.
 */
instruct_func get_opcode_func(char *str)
{
	int i;

	instruction_t instruct[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"pchar", monty_pchar},
		{"add", monty_add},
		{"sub", monty_sub},
		{"mul", monty_mul},
		{"div", monty_div},
		{"mod", monty_mod},
		{"nop", monty_nop},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"pstr", monty_pstr},
		{"stack", monty_stack},
		{"queue", monty_queue},
		{NULL, NULL},
	};

	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}
