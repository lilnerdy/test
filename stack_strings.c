#include "monty.h"

/**
 * prnt_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_numb: Interger representing the line number of of the opcode.
 */
void prnt_char(stack_t **stack, unsigned int l_numb)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_ero(11, l_numb);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_ero(10, l_numb);
	printf("%c\n", ascii);
}

/**
 * print_stri - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void print_stri(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int asci;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		asci = tmp->n;
		if (asci <= 0 || asci > 127)
			break;
		printf("%c", asci);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
