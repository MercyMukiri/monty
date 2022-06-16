#include "monty.h"

stack_t *head = NULL;

/**
 * create_node - creates a node
 *
 * @n: number placed inside the node
 *
 * Return: a pointer to the node on success, otherwise NULL
 */

stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));

	if (node == NULL)
		err(4);

	node->next = NULL;
	node->prev = NULL;
	node->n = n;

	return (node);
}

/**
 * free_nodes - frees nodes in the stack
 *
 * Return: void
 */

void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * add_to_queue - adds a node to the queue
 *
 * @new_node: pointer to the new node
 * @line_no: line number of the opcode
 *
 * Return: void
 */

void add_to_queue(stack_t **new_node,
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}

/**
 * main - entry point
 *
 * @argc: arguments count
 * @argv: list of arguments
 *
 * Return: Always 0 (SUCCESS)
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");

		exit(EXIT_FAILURE);
	}

	open_file(argv[1]);
	free_nodes();

	return (0);
}
