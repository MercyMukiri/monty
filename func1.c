#include "monty.h"

/**
 * nop - does nothing
 *
 * @stack: double pointer to the top node of the stack
 * @line_no: integer representing the line number of the opcode
 *
 * Return: void
 */

void nop(stack_t **stack, unsigned int line_no)
{
	(void)stack;
	(void)line_no;
}

/**
 * swap_nodes - swaps the top two elements of the stack
 *
 * @stack: double pointer to the top node of the stack
 * @line_no: integer representing the line number of the opcode
 *
 * Return: void
 */

void swap_nodes(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_no, "swap");

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *stack;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_nodes - adds the top two elements of the stack
 *
 * @stack: double pointer to the top node of the stack
 * @line_no: interger representing the line number of the opcode
 *
 * Return: void
 */

void add_nodes(stack_t **stack, unsigned int line_no)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_no, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nodes - subtracts the top two elements of the stack
 *
 * @stack: double pointer to the top node of the stack
 * @line_no: integer representing the line number of the opcode
 *
 * Return: void
 */

void sub_nodes(stack_t **stack, unsigned int line_no)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_no, "sub");

	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes - divides the top two elements of the stack
 *
 * @stack: double pointer to the top node of the stack
 * @line_no: integer representing the line number of the opcode
 *
 * Return: void
 */

void div_nodes(stack_t **stack, unsigned int line_no)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_no, "div");

	if ((*stack)->n == 0)
		more_err(9, line_no);

	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
