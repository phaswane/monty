#include "monty.h"

/**
 * printIntegerFromTop - prints the value at the top of the stack
 * @stack: pointer to head/top
 * @line_number: current line number
 * Return: void
 */

void printIntegerFromTop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	if (temp == NULL)
	{
		free(global.content);
		fclose(global.file);
		free_stack(stack);
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}

/**
 * popElement - removes the top element of the stack
 * @stack: pointer to top/head
 * @line_number: current line number
 * Return: void
 */

void popElement(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(global.content);
		fclose(global.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next)
	{
		*stack = temp->next;
		(*stack)->prev = NULL;
		free(temp);
	}
	else
		free_stack(stack);
}

