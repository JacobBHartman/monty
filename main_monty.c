#include "monty.h"

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

	if (stack == NULL)
		return (NULL);

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
		return (NULL);

	temp->n = 5;
	temp->prev = NULL;
	temp->next = *stack;

	*stack = temp;
	if ((*stack)->next != NULL)
		temp->next->prev = *stack
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

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


/**
 * op - chooses the appropriate operation based on the opcode
 * @opcode: the operation code
 *
 * Return: a pointer to a function that takes a stack and line# and returns vd
 */
void (*op(char *opcode))(stack_t, unsigned int)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int index;

	for (index = 0; instructions[index].opcode != NULL; index++)
		if (strcmp(instructions[index].opcode, opcode) == 0)
			return (instructions[index].f);
	return (instructions[index].f);
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
	/* initialize the file */
	FILE *file_to_read = NULL;

	char **buffer = NULL;
	size_t *buffer_size = 0;

	int index;
	int token_count;
	char *delimiters = "\n \t";
	char *opcode = NULL;

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

	// read and parse the file
	n_arguments = 2;
	n_characters_read = getline(buffer, buffer_size, file_to_read);
	if (n_characters_read == -1)
	{
		printf("Error: Unable to read line\m");
		exit(EXIT_FAILURE);
	}
	opcode = strtok(buffer, delimiters);
	if (opcode == NULL)
	{
		printf("L<line_number>: unknown instruction <opcode>\n");
		exit(EXIT_FAILURE)
	}
	// go to the next line
	first_argument = atoi(strtok(NULL, delimiters));

	/* exit stage right */
	return (0);
}
