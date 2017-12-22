#include "monty.h"

/**
 * parseMontyFile - parses and reads a monty file
 *
 * Return: void
 */
void parseMontyFile(void)
{
	int i;
	size_t buffer_size;
	char *delimiters = "\n \t";
	void (*f)(stack_t **, unsigned int);

	buffer_size = 0; /* read and parse the file */
	while (getline(&var->buffer, &buffer_size, var->file_address) != -1)
	{
		var->line_num++;

		/* select the proper operation(s) */
		var->opcode = strtok(var->buffer, delimiters);

		/* check for comments and empty lines */
		if (var->opcode == NULL || var->opcode[0] == '#')
			continue;

		f = op(var->opcode);
		if (f == NULL)
			handleError(600);

		if (strcmp(var->opcode, "push") == 0)
		{
			var->arg_one = strtok(NULL, delimiters);
			if (var->arg_one == NULL)
				handleError(500);
			for (i = 0; var->arg_one[i] != '\0'; i++)
				if (isdigit(var->arg_one[i]) == 0)
					if (var->arg_one[i] != '-')
						handleError(500);
			var->daata = atoi(var->arg_one);
		}
		f(&var->top, var->line_num);
	}
}
