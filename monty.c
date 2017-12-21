#include "monty.h"

var_t *var;

/**
 * handleError - handles errors and exits
 * @error_code - determines why the program was exited
 *
 * Return: void
 */
void handleError(unsigned int error_code)
{
	if (error_code == 200) /* improper usage from command line */
		printf("USAGE: monty file\n");
	if (error_code == 300) /* unable to open the file */
		printf("Error: Can't open file %s\n", var->file_name);
	if (error_code == 400) /* unable to malloc */
		printf("Error: malloc failed\n");
	if (error_code == 500) /* improper usage of push */
		printf("L%d: usage: push integer\n", var->line_num);
	if (error_code == 600) /* unknown instruction */
	{
		printf("L%d: unknown ", var->line_num);
		printf("instruction %s\n", var->opcode);
	}
	if (error_code == 700) /* unable to pint */
		printf("L%d: can't pint, stack empty\n", var->line_num);
	if (error_code == 800) /* unable to pop */
		printf("L%d: can't pop an empty stack\n", var->line_num);
	if (error_code == 900)	/* unable to swap */
		printf("L%d: can't swap, stack too short\n", var->line_num);
	if (error_code == 1000) /* unable to add */
		printf("L%d: can't add, stack too short\n", var->line_num);

	if (var->top != NULL)
		freeStack(var->top);
	if (var->buffer != NULL)
		free(var->buffer);
	if (var->file_address != NULL)
		fclose(var->file_address);

	exit(EXIT_FAILURE);
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
	size_t buffer_size;
	int i; /* index */
	char *delimiters = "\n \t";
	char *arg_one = NULL;
	void (*f)(stack_t **, unsigned int);

	var_t init = {NULL, NULL, 0, NULL, 0, NULL, NULL};
	var = &init;
	var->file_name = argv[1];

	/* check for proper usage from command line */
	if (argc != 2)
		handleError(200);

	/* open the file and check if it was opened */
	var->file_address = fopen(var->file_name, "r");
	if (var->file_address == NULL)
		handleError(300);

	/* read and parse the file */
	buffer_size = 0;
	while (getline(&var->buffer, &buffer_size, var->file_address) != -1)
	{
		var->line_num++;

		/* select the proper operation(s) */
		var->opcode = strtok(var->buffer, delimiters);

		/* check for only spaces or newline */
		if (var->opcode == NULL)
			continue;

		f = op(var->opcode);
		if (f == NULL)
			handleError(600);

		if (strcmp(var->opcode, "push") == 0)
		{
			arg_one = strtok(NULL, delimiters);
			if (arg_one == NULL)
				handleError(500);
			for (i = 0; arg_one[i] != '\0'; i++)
				if (isdigit(arg_one[i]) == 0 && arg_one[i] != '-')
					handleError(500);
			var->daata = atoi(arg_one);
		}
		f(&var->top, var->line_num);
	}

	free(var->buffer);
	if (var->top != NULL)
		freeStack(var->top);
	fclose(var->file_address);

	/* exit stage right */
	return (0);
}

/* convert all ints to unsigned if its not necessary to have negatives */
/* review variable names */
