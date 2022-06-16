#include "monty.h"

/**
 * open_file - opens a file
 *
 * @file_name: the file namepath
 *
 * Return: void
 */

void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);

	read_file(fd);
	fclose(fd);
}


/**
 * read_file - reads a file
 *
 * @fd: pointer to file descriptor
 *
 * Return: void
 */

void read_file(FILE *fd)
{
	int line_no, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_no = 1; getline(&buffer, &len, fd) != -1; line_no++)
	{
		format = parse_line(buffer, line_no, format);
	}

	free(buffer);
}


/**
 * parse_line - separates each line into tokens
 *
 * @buffer: line from the file
 * @line_no: line number for the instruction
 * @format:  Format specifier. 0 nodes - stack, 1 node - queue
 *
 * Return: returns 0 if the opcode is stack, 1 if queue
 */

int parse_line(char *buffer, int line_no, int format)
{
	char *opcode, *val;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);

	if (opcode == NULL)
		return (format);

	val = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);

	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, val, line_no, format);

	return (format);
}

/**
 * find_func - finds the appropriate function for the opcode
 *
 * @opcode: string representing the opcode
 * @val: string representing a numeric value
 * @line_no: line number for the instruction
 * @format: Format specifier. 0 nodes - stack, 1 node - queue
 *
 * Return: void
 */

void find_func(char *opcode, char *val, int line_no, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_func(func_list[i].f, opcode, val, line_no, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, line_no, opcode);
}


/**
 * call_func - calls a function
 *
 * @func: pointer to the function that is about to be called
 * @opcode: string representing the opcode
 * @val: string representing a numeric value
 * @line_no: line number for the instruction
 * @format: Format specifier. 0 nodes - stack, 1 node - queue
 *
 * Return: void
 */

void call_func(op_func func, char *opcode, char *val, int line_no, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}

		if (val == NULL)
			err(5, line_no);

		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, line_no);
		}

		node = create_node(atoi(val) * flag);

		if (format == 0)
			func(&node, line_no);

		if (format == 1)
			add_to_queue(&node, line_no);
	}
	else
		func(&head, line_no);
}
