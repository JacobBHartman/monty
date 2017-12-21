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
        (void) line_number;

        if (stack == NULL)
                return;

        temp = malloc(sizeof(stack_t));
        if (temp == NULL)
		handleError(400);

        temp->n = var->daata;
        temp->prev = NULL;
        temp->next = *stack;

        *stack = temp;
        if ((*stack)->next != NULL)
                temp->next->prev = *stack;
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
        line_number++; /* WHAT TO DO WITH THIS? */

        while (temp != NULL)
        {
                printf("%d\n", temp->n);
                temp = temp->next;
        }
}
