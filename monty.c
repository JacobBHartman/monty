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
	/* improper usage from command line */
	if (error_code == 200)
		printf("USAGE: monty file\n");

	/* unable to open the file */
	if (error_code == 300)
		printf("Error: Can't open file %s\n", var->file_name);

	/* unable to malloc */
	if (error_code == 400)
	{
                printf("Error: malloc failed\n");
		freeStack(var->top);
		/* FREE OTHER STUFF? */
        }

	/* improper usage of push */
	if (error_code == 500)
	{
		printf("L%d: usage: push integer\n", var->line_number);
		freeStack(var->top);
		fclose(var->file_address);
		free(var->buffer);
	}

	/* unknown instruction */
	if (error_code == 600)
	{
		printf("L%d: unknown ", var->line_number);
		printf("instruction %s\n", var->opcode);
		freeStack(var->top);
		free(var->buffer);
		fclose(var->file_address);
	}

	/* unable to pint */
	if (error_code == 700)
	{
		printf("L%d: can't pint, stack empty\n", var->line_number);
		free(var->buffer);
		fclose(var->file_address);
	}

	/* unable to pop */
	if (error_code == 800)
	{
		printf("L%d: can't pop an empty stack\n", var->line_number);
		free(var->buffer);
		fclose(var->file_address);
	}

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
		var->line_number++;

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
		f(&var->top, var->line_number);
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
