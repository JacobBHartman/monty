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
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divideStack},
		{"mul", multiplyStack},
		{"mod", moduloStack},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotateLeft},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
		if (strcmp(instructions[i].opcode, opcode) == 0)
			return (instructions[i].f);
	return (instructions[i].f);
}
