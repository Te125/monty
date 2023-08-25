#include "monty.h"

/**
 * swap - function that swaps the top two elements of the stack
 * @stack: head of the stack, double pointer
 * @num: integer
 */
void swap(stack_t **stack, unsigned int num)
{
	stack_t *swa = *stack;
	stack_t *swa_t = (*stack)->next;
	int i = 0;

	if (*stack || (*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", num);
		exit(EXIT_FAILURE);
	}

	i = swa->n;
	swa->n = swa_t->n;
	swa_t->n = i;
}

/**
 * add - function that adds the top two elements of the stack
 * @stack: double pointer at the head of the stack
 * @num: integer
 */
void add(stack_t **stack, unsigned int num)
{
	stack_t *ad = *stack;
	stack_t *ad_t = ad->next;
	int i = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", num);
		exit(EXIT_SUCCESS);
	}

	i = ad->n + ad_t->n;
	(*stack)->n = i;
}

/**
 * nop - function that does nothing
 * @stack: double pointer at the head of the stack
 * @num: integer
 */
void nop(stack_t **stack, unsigned int num)
{
	(void)stack;
	(void)num;
}
