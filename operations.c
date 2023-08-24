#include "monty.h"

/**
 * noOperation - does nothing
 * @stack: pointer to head/top
 * @line_number: current line number
 * Return: nothing
 */

void noOperation(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}

/**
 * subtractTopTwoElements - subtract top element of stack from second top element of stack.
 * @stack: pointer to head/top
 * @line_number: current line number
 * Return: nothing
 */

void subtractTopTwoElements(stack_t **stack, unsigned int line_number)
{
	int diff = 0;
	stack_t *temp_2;
	stack_t *temp_1;


	if (*stack && (*stack)->next)
	{
		temp_2 = (*stack)->next;
		diff = temp_2->n - (*stack)->n;
		temp_1 = *stack;
		*stack = (*stack)->next;
		if (*stack)
		{
			(*stack)->prev = NULL;
		}
		free(temp_1);
		(*stack)->n = diff;
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free(global.content);
		fclose(global.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
