#include "monty.h"

/**
 * funct - pointers to functions
 * @token: opcode
 * Return: fuction
 */

void (*funct(char *token))(stack_t **stack, unsigned int line_number)
{
	instruction_t opco[] = {
		{"push", pushElement},
		{"pall", printAllElements},
		{"pint", printIntegerFromTop},
		{"pop", popElement},
		{"swap", swapTopTwoElements},
		{"add", addTopTwoElements},
		{"nop", noOperation},
		{"sub", subtractTopTwoElements},
		{"err", handleErrors},
		{"div", divideTopTwoElements},
		{"mul", multiplyTopTwoElements},
		{"mod", calculateModulus},
		{"#", noOperation},
		{"pstr", printStringFromTop},
		{"pchar", printCharFromTop},
		{"rotl", rotateLeft},
		{"rotr", rotateRight},
		{"stack", switchToStackMode},
		{"queue", enqueueElement},
		{NULL, NULL}};
	int i = 0;
	int op;

	while (i < 19)
	{
		op = strcmp(token, opco[i].opcode);
		if (op == 0)
		{
			return (opco[i].f);
		}
		i++;
	}
	return (opco[8].f);
}
/**
 * handleErrors - manage the error if instruction is invalid
 * @stack: pointer to top/head
 * @line_number: line number
 */
void handleErrors(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, global.content);
	free(global.content);
	fclose(global.file);
	free_stack(stack);
	exit(EXIT_FAILURE);
}



/**
 * divideTopTwoElements - divides second top element of the stack
 *	by the top element of the stack
 * @stack: pointer to top/head
 * @line_number: current line number
 */
void divideTopTwoElements(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int div = 0;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			free(global.content);
			fclose(global.file);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		div = temp->next->n / temp->n;
		temp->next->n = div;
		*stack = temp->next;
		free(temp);
		if (*stack)
		{
			(*stack)->prev = NULL;
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free(global.content);
		fclose(global.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * multiplyTopTwoElements - multiplies second top element of the stack
 *	by the top element of the stack
 * @stack: pointer to top/head
 * @line_number: current line number
 */
void multiplyTopTwoElements(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int mul = 0;

	if (*stack && (*stack)->next)
	{
		mul = temp->next->n * temp->n;
		temp->next->n = mul;
		*stack = temp->next;
		free(temp);
		if (*stack)
		{
			(*stack)->prev = NULL;
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free(global.content);
		fclose(global.file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
