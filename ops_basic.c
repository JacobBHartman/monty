#include "monty.h"

/**
 * push - pushes a piece of data to the top of the stack
 * @stack: a pointer to a pointer to a doubly linked list (stack)
 * @line_number: the number of the line at which push was called
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	stack_t *temp_q;

	(void) line_number;
	if (stack == NULL)
		return;

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
		handleError(400);

	temp->n = var->daata;
	if (var->top == NULL)
	{
		temp->prev = NULL;
		temp->next = NULL;
		var->top = temp;
		return;
	}

	temp_q = var->top;
	if (var->queue_mode == 0)
	{
		temp->prev = NULL;
		temp->next = var->top;
		var->top = temp;
		if (var->top->next != NULL)
			temp->next->prev = var->top;
	}
	else
	{
		temp->next = NULL;
		while (temp_q->next != NULL)
		       temp_q = temp_q->next;
		temp->prev = temp_q;
		temp_q->next = temp;
	}
}

/**
 * pall - prints all of the nodes in the stack
 * @stack: a pointer to a pointer to a doubly linked list (stack)
 * @line_number: the number of the line at which pall was called
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: a pointer to a pointer to a doubly linked list (stack)
 * @line_number: the number of the line at which pall was called
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	if (var->top == NULL)
		handleError(700);
	printf("%d\n", var->top->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: a pointer to a pointer to a doubly linked list (stack)
 * @line_number: the number of the line at which pop was called
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	(void) stack;

	if (var->top == NULL)
		handleError(800);

	temp = var->top->next;
	free(var->top);
	var->top = temp;
}
