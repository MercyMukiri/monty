#include "monty.h"

/**
 * mul_nodes - multiplies the top two elements of the stack
 *
 * @stack: double pointer to the top node of the stack
 * @line_no: interger representing the line number of the opcode
 *
 * Return: void
 */

void mul_nodes(stack_t **stack, unsigned int line_no)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_no, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes - divides the second top element of the stack by the top element
 *
 * @stack: double pointer to the top node of the stack
 * @line_no: interger representing the line number of the opcode
 *
 * Return: void
 */

void mod_nodes(stack_t **stack, unsigned int line_no)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_no, "mod");

	if ((*stack)->n == 0)
		more_err(9, line_no);

	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
