#include "monty.h"

/**
 * op - chooses the appropriate operation based on the opcode
 * @opcode: the operation code
 *
 * Return: a pointer to a function that takes a stack and line# and returns vd
 */
void (*op(char *opcode))(stack_t **, unsigned int)
{
        instruction_t instructions[] = {
                {"push", push},
                {"pall", pall},
		{"pint", pint},
		{"pop", pop},
                {NULL, NULL}
        };
        int index;

        for (index = 0; instructions[index].opcode != NULL; index++)
                if (strcmp(instructions[index].opcode, opcode) == 0)
                        return (instructions[index].f);
        return (instructions[index].f);
}
