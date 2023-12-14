#include "monty.h"

/**
 * Nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_numb: Interger representing the line number of of the opcode.
 */
void Nop(stack_t **stack, unsigned int l_numb)
{
	(void)stack;
	(void)l_numb;
}


/**
 * Swap_nodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_numb: Interger representing the line number of of the opcode.
 */
void Swap_nodes(stack_t **stack, unsigned int l_numb)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_ero(8, l_numb, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * Add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_numb: Interger representing the line number of of the opcode.
 */
void Add_nodes(stack_t **stack, unsigned int l_numb)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_ero(8, l_numb, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * Sub_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_numb: Interger representing the line number of of the opcode.
 */
void Sub_nodes(stack_t **stack, unsigned int l_numb)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_ero(8, l_numb, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
