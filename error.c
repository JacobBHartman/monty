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
        if (error_code == 900)  /* unable to swap */
                printf("L%d: can't swap, stack too short\n", var->line_num);
        if (error_code == 1000) /* unable to add */
                printf("L%d: can't add, stack too short\n", var->line_num);
	if (error_code == 1100) /* unable to subtract */
		printf("L%d: can't sub, stack too short\n", var->line_num);
	if (error_code == 1200) /* unable to divide */
		printf("L%d: can't div, stack too short\n", var->line_num);
	if (error_code == 1300) /* divide by zero */
		printf("L%d: division by zero\n", var->line_num);
	cleanFreeAndClose();

        exit(EXIT_FAILURE);
}
