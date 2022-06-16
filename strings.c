#include "monty.h"

/**
 * print_char - prints the Ascii value
 *
 * @stack: double pointer to the top node of the stack
 * @line_no: Integer representing the line number of the opcode
 *
 * Return: void
 */

void print_char(stack_t **stack, unsigned int line_no)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_no);

	ascii = (*stack)->n;

	if (ascii < 0 || ascii > 127)
		string_err(10, line_no);

	printf("%c\n", ascii);
}

/**
 * print_str - prints a string
 *
 * @stack: double pointer to the top node of the stack
 * @line_no: integer representing the line number of the opcode
 *
 * Return: void
 */

void print_str(stack_t **stack, __attribute__((unused))unsigned int line_no)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");

		return;
	}

	tmp = *stack;

	while (tmp != NULL)
	{
		ascii = tmp->n;

		if (ascii <= 0 || ascii > 127)
			break;

		printf("%c", ascii);
		tmp = tmp->next;
	}

	printf("\n");
}

/**
 * rotl - rotates the first node of the stack to the bottom
 *
 * @stack: double pointer to the top node of the stack
 * @line_no: integer representing the line number of the opcode
 *
 * Return: void
 */

void rotl(stack_t **stack, __attribute__((unused))unsigned int line_no)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - rotates the last node of the stack to the top
 *
 * @stack: double pointer to the top node of the stack
 * @line_no: integer representing the line number of the opcode
 *
 * Return: void
 */

void rotr(stack_t **stack, __attribute__((unused))unsigned int line_no)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
