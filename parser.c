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
        char *arg_one = NULL;
        void (*f)(stack_t **, unsigned int);

        buffer_size = 0; /* read and parse the file */
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
}
