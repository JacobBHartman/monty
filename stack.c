#include "monty.h"

/**
 * freeStack - frees a doubly linked list (stack)
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

/**
 * onStack - turns on Stack mode (queue off)
 * @stack: a pointer to a pointer to a doubly linked list
 * @line_number: the line number at which stack was called
 *
 * Return: void
 */
void onStack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	var->queue_mode = 0;
}

/**
 * onQueue - turns on queue mode (stack off)
 * @queue: a pointer to a pointer to a doubly linked list
 * @line_number: the line number at which stack was called
 *
 * Return: void
 */
void onQueue(stack_t **queue, unsigned int line_number)
{
	(void) queue;
	(void) line_number;
	var->queue_mode = 1;
}
