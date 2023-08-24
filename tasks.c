#include "monty.h"

/**
 * push - function that pushes an element to the stack
 * @stack: head of the stack
 * @num: integer to be parsed
 *
 */
void push(stack_t **stack, int num)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (node == 0)
	{
		fprintf(stderr, "Error: Malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = num;
	node->prev = NULL;
	node->next = *stack;
	if (*stack)
	{
		(*stack)->prev = node;
	}
	*stack = node;
}

/**
 * pall - function that prints all values on the stack
 * starting from the top
 * @stack: where to print values from
 *
 */
void pall(stack_t **stack)
{
	stack_t *pal = *stack;

	if (!pal)
	{
		return;
	}
	while (pal)
	{
		printf("%d\n", pal->n);
		pal = pal->next;
	}
}
