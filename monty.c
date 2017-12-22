#include "monty.h"

var_t *var;

/**
 * main - controls the program flow for monty
 * @argc: the number of arugments
 * @argv: a pointer to an array of strings that contains the arguments
 *
 * Return: 0 if successful, 1 if not
 */
int main(int argc, char *argv[])
{
	var_t init = {NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, 0};

	var = &init;
	var->file_name = argv[1];

	if (argc != 2)
		handleError(200);

	var->file_address = fopen(var->file_name, "r");
	if (var->file_address == NULL)
		handleError(300);

	parseMontyFile();

	cleanFreeAndClose();

	return (0);
}
