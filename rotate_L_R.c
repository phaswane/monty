#include "monty.h"

/**
 * rotateLeft - rotates the stack to the top.
 * @stack: pointer to head
 * @line_number: current number line
 * Return: void
 */

void rotateLeft(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_1;
	stack_t *temp_2;

	if (*stack && (*stack)->next)
	{
		temp_1 = *stack;
		temp_2 = temp_1;
		*stack = temp_1->next;
		(*stack)->prev = NULL;

		if (line_number)
			while (temp_2->next)
			{
				temp_2 = temp_2->next;
			}
		temp_2->next = temp_1;
		temp_1->prev = temp_2;
		temp_1->next = NULL;
	}
}

/**
 * rotateRight - rotates the stack to the bottom
 * @stack: pointer to head
 * @line_number: current num line
 * Return: void
 */

void rotateRight(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_2;

	if (*stack && (*stack)->next)
	{
		temp_2 = *stack;
		if (line_number)
			while (temp_2->next)
			{
				temp_2 = temp_2->next;
			}
		temp_2->next = *stack;
		temp_2->prev->next = NULL;
		temp_2->prev = NULL;
		*stack = temp_2;
	}
}

