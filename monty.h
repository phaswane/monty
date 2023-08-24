#ifndef MONTY_H
#define MONTY_H

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - global variables
 * @token: operand
 * @num: value to store in stack
 * @code: instruction
 * @file: pointer to monty file descriptor
 * @content: line content
 * @flag: change stack <-> queue
 * Description: carries values through the program
 */
typedef struct global_s
{
	char *code;
	char *token;
	FILE *file;
	char *content;
	int flag;
	int num;
}  global_t;

extern global_t global;
char add_null(char *line);
int line_len(char *line);

void free_stack(stack_t **stack);

void (*funct(char *token))(stack_t **stack, unsigned int line_number);

void multiplyTopTwoElements(stack_t **stack, unsigned int line_number);
void calculateModulus(stack_t **stack, unsigned int line_number);
void printCharFromTop(stack_t **stack, unsigned int line_number);
void printStringFromTop(stack_t **stack, unsigned int line_number);
void rotateLeft(stack_t **stack, unsigned int line_number);
void rotateRight(stack_t **stack, unsigned int line_number);
void enqueueElement(stack_t **stack, unsigned int line_number);
void switchToStackMode(stack_t **stack, unsigned int line_number);
void pushElement(stack_t **stack, unsigned int line_number);
void printAllElements(stack_t **stack, unsigned int line_number);
void printIntegerFromTop(stack_t **stack, unsigned int line_number);
void popElement(stack_t **stack, unsigned int line_number);
void swapTopTwoElements(stack_t **stack, unsigned int line_number);
void addTopTwoElements(stack_t **stack, unsigned int line_number);
void noOperation(stack_t **stack, unsigned int line_number);
void subtractTopTwoElements(stack_t **stack, unsigned int line_number);
void handleErrors(stack_t **stack, unsigned int line_number);
void divideTopTwoElements(stack_t **stack, unsigned int line_number);
void _verify(stack_t **stack, unsigned int line_number);

int check_int(char *num);

#endif 

