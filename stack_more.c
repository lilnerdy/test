#include "monty.h"

/**
 * Div_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_numb: Interger representing the line number of of the opcode.
 */
void Div_nodes(stack_t **stack, unsigned int l_numb)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_ero(8, l_numb, "div");

	if ((*stack)->n == 0)
		more_ero(9, l_numb);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * Mul_nodes - mutiplication of the top two elements of the stack.
 * @stack: Points to a pointer pointing to top node of the stack.
 * @l_numb: Interger representing the line number of of the opcode.
 */
void Mul_nodes(stack_t **stack, unsigned int l_numb)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_ero(8, l_numb, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * Mod_nodes - Mod of the top two elements of the stack.
 * @stack: Points to a pointer pointing to top node of the stack.
 * @l_numb: Int representing the line number of of the opcode.
 */
void Mod_nodes(stack_t **stack, unsigned int l_numb)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_ero(8, l_numb, "mod");


	if ((*stack)->n == 0)
		more_ero(9, l_numb);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
