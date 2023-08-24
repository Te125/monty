#include "monty.h"

/**
 * free_s - function that free dynamically allocated memory
 * in the stack
 * @stack: memory
 *
 */
void free_s(stack_t *stack)
{
	while (stack)
	{
		stack_t *joy = stack;
		stack = stack->next;
		free(joy);
	}
}
