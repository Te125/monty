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

/**
 * pint - function that prints value at the top of the stack
 * @stack: head of the stack
 * @num: integer to be called
 *
 */
void pint(stack_t **stack, unsigned int num)
{
	stack_t *pin = *stack;

	if (pin == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", num);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", pin->n);
}

/**
 * pop - function that removes the top element of the stack
 * @stack: head of the stack
 * @num: integer to be removed
 *
 */
void pop(stack_t **stack, unsigned int num)
{
	stack_t *po = *stack;

	*stack = po->next;
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", num);
		exit(EXIT_FAILURE);
	}
	if (*stack)
	{
		(*stack)->prev = NULL;
	}

	free(po);
}
