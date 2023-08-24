#include "monty.h"

/**
 * swapTopTwoElements - swaps the top two elements of the stack
 * @stack: pointer to top/head
 * @line_number: current line number
 * Return: void
 */
void swapTopTwoElements(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->next;
		if (temp == NULL)
		{
			exit(0);
		}
		(*stack)->next = temp->next;
		(*stack)->prev = temp;
		temp->next = *stack;
		temp->prev = NULL;
		*stack = temp;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(global.content);
		fclose(global.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
/**
 * addTopTwoElements - adds the top two elements of the stack.
 * @stack: pointer to top/head
 * @line_number: current line number
 * Return: void
 */
void addTopTwoElements(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *temp_1;
	stack_t *temp_2;

	if (*stack && (*stack)->next)
	{
		temp_2 = (*stack)->next;
		sum = (*stack)->n + temp_2->n;
		temp_1 = *stack;
		*stack = (*stack)->next;
		if (*stack)
		{
			(*stack)->prev = NULL;
		}
		free(temp_1);
		(*stack)->n = sum;
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(global.content);
		fclose(global.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}

