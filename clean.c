#include "monty.h"

/**
 * cleanFreeAndClose - clean up by freeing and closing heaps and files
 *
 * Return: void
 */
void cleanFreeAndClose(void)
{
	if (var->top != NULL)
		freeStack(var->top);
	if (var->buffer != NULL)
		free(var->buffer);
	if (var->file_address != NULL)
		fclose(var->file_address);
}
