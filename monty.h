#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#define BUFFER 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/uio.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void free_s(stack_t *stack);
void file_hand(const char *file);
void tokenize(char *buf, int p, stack_t **stack);
int main(int argc, char *argv[]);
void push(stack_t **stack, int num);
void pall(stack_t **stack);
void pint(stack_t **stack, unsigned int num);
void pop(stack_t **stack, unsigned int num);
void swap(stack_t **stack, unsigned int num);
void add(stack_t **stack, unsigned int num);
void nop(stack_t **stack, unsigned int num);


#endif
