#include "monty.h"

int daata = 0;

/**
 * push - pushes a piece of data to the top of the stack
 * @stack: a pointer to a pointer to a doubly linked list (stack)
 * @line_number: the number of the line at which push was called
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	line_number++; /* WHAT TO DO WITH THIS? */

	if (stack == NULL)
		return;

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		free(temp);
		return;
	}

	temp->n = daata;
	temp->prev = NULL;
	temp->next = *stack;

	*stack = temp;
	if ((*stack)->next != NULL)
		temp->next->prev = *stack;
}

/**
 * pall - prints all of the nodes in the stack
 * @stack: a pointer to a pointer to a doubly linked list (stack)
 * @line_number: the number of the line at which pall was called
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	line_number++; /* WHAT TO DO WITH THIS? */

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * main - controls the program flow for monty
 * @argc: the number of arugments
 * @argv: a pointer to an array of strings that contains the arguments
 *
 * Return: 0 if successful, 1 if not
 */
int main(int argc, char *argv[])
{
	FILE *file_to_read = NULL;

	char *buffer = NULL;
	size_t buffer_size = 0;

	stack_t *top;

	int i; /* index */
	char *delimiters = "\n \t";
	char *opcode = NULL;
	char *arg_one = NULL;
	ssize_t n_characters_read = 1;
	void (*f)(stack_t **, unsigned int);
	unsigned int line_number = 0;

	/* check if argument count is correct (CAN BE PORTED TO ERROR FUNC) */
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* open the file and check if it was opened (CAN BE PORTED 2 ERRORFNC */
	file_to_read = fopen(argv[1], "r");
	if (file_to_read == NULL)
	{
		printf("Error: Can't open file <file>\n"); /* PRINT FILE NAME */
		exit(EXIT_FAILURE);
	}
	// create the stack
	top = NULL;

	// read and parse the file
	while (getline(&buffer, &buffer_size, file_to_read) != -1)
	{
		line_number++;
		if (n_characters_read == -1)
		{
			printf("Error: Unable to read line\n");
			exit(EXIT_FAILURE);
		}

		/* select the proper operation(s) */
		opcode = strtok(buffer, delimiters);
		f = op(opcode);
		if (f == NULL)
		{
			printf("L%d: ", line_number);
			printf("unknown instruction %s\n", opcode);
			exit(EXIT_FAILURE);
		}
		if (arg_one == NULL)
			daata = 0;
		if (strcmp(opcode, "push") == 0)
		{
			arg_one = strtok(NULL, delimiters);
			for (i = 0; arg_one[i] != '\0'; i++)
			{
				if (isdigit(arg_one[i]) == 0)
				{
					printf("L%d: ", line_number);
					printf("usage: push integer\n");
					exit(EXIT_FAILURE);
				}
			}
			daata = atoi(arg_one);
		}
		f(&top, line_number);
	}

	return (0); /* exit stage right */
}

/* convert all ints to unsigned if its not necessary to have negatives */
/* review variable names */
