#include "monty.h"


/**
 * add_to_stack - adds a node to the stack
 *
 * @new_node: double pointer to the new node.
 * @line_no: interger representing the line number of of the opcode
 *
 * Return: void
 */

void add_to_stack(stack_t **new_node,
		  __attribute__((unused))unsigned int line_no)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *new_node;

		return;
	}

	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * print_stack - prints the stack
 *
 * @stack: double pointer to the top node of the stack
 * @line_no: integer representing the line number of  the opcode
 *
 * Return: void
 */

void print_stack(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp;

	(void) line_no;

	if (stack == NULL)
		exit(EXIT_FAILURE);

	tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_top - adds a node to the stack
 *
 * @stack: double pointer to the top node of the stack
 * @line_no: interger representing the line number of of the opcode
 *
 * Return: void
 */

void pop_top(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_no);

	tmp = *stack;
	*stack = tmp->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(tmp);
}

/**
 * print_top - prints the top node of the stack
 *
 * @stack: double pointer to the top node of the stack
 * @line_no: interger representing the line number of the opcode
 *
 * Return: void
 */

void print_top(stack_t **stack, unsigned int line_no)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_no);

	printf("%d\n", (*stack)->n);
}
