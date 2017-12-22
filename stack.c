#include "monty.h"

/**
 * free_stack - frees a doubly linked list (stack)
 * @top: a pointer to a doubly linked list (stack)
 *
 * Return: void
 */
void freeStack(stack_t *top)
{
	stack_t *temp = top;
	while (temp != NULL)
	{
		temp = top->next;
		free(top);
		top = temp;
	}
}
