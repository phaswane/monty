#include "monty.h"

/**
 * enqueueElement - sets the format of the data to a queue (FIFO)
 * @stack: head
 * @line_number: current number line
 * Return: void
 */

void enqueueElement(stack_t **stack, unsigned int line_number)
{
	if (stack || line_number)
	{
		global.flag = 0;
	}
}

/**
 * switchToStackMode - sets the format of the data to a stack (LIFO)
 * @stack:pointer to head
 * @line_number: num line
 * Return: void
 */

void switchToStackMode(stack_t **stack, unsigned int line_number)
{
	if (stack || line_number)
	{
		global.flag = 1;
	}
}
