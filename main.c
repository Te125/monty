#include "monty.h"

/**
 * main - main function for the monty program
 * @argc: argument count
 * @argv: array of argument vector
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_hand(argv[1]);

	return (EXIT_SUCCESS);
}

/**
 * file_hand - function for handling files
 * @file: name of file to be handled
 *
 */
void file_hand(const char *file)
{
	FILE *fdp;
	stack_t *stack = NULL;
	char buf[BUFFER];
	int p = 0;

	fdp = fopen(file, "r");
	if (fdp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while (fgets(buf, sizeof(buf), fdp) != NULL)
	{
		p++;
		tokenize(buf, p, &stack);
	}

	fclose(fdp);
	free_s(stack);
}

/**
 * tokenize - function to tokenize strings
 * @buf: buffer
 * @p: integer
 * @stack: where the tokenization is going to take place
 *
 */
void tokenize(char *buf, int p, stack_t **stack)
{
	char *token;
	int i = 0;

	token = strtok(buf, " \t\r\n");
	if (token == NULL || token[0] == '#')
	{
		return;
	}
	if (strcmp(token, "push") == 0)
	{
		token = strtok(NULL, " \t\r\n");
		if (token == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", p);
			exit(EXIT_FAILURE);
		}
		i = atoi(token);
		push(stack, i);
	}
	else if (strcmp(token, "pall") == 0)
	{
		pall(stack);
	}
	else if (strcmp(token, "pint") == 0)
	{
		pint(stack, p);
	}
	else if (strcmp(token, "pop") == 0)
	{
		pop(stack, p);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", p, token);
		exit(EXIT_FAILURE);
	}
}
