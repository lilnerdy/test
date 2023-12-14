#include "monty.h"


/**
 * add_t_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void add_t_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * prnt_stack - print the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_numb: line number of  the opcode.
 */
void prnt_stack(stack_t **stack, unsigned int l_numb)
{
	stack_t *tmp;

	(void) l_numb;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_topn - Adds a node to the stack.
 * @stack: Points to a pointer pointing to top node of the stack.
 * @l_numb: Interger representing the line number of of the opcd.
 */
void pop_topn(stack_t **stack, unsigned int l_numb)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_ero(7, l_numb);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * print_topn - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_numb: Interger representing the line number of of the opcode.
 */
void print_topn(stack_t **stack, unsigned int l_numb)
{
	if (stack == NULL || *stack == NULL)
		more_ero(6, l_numb);
	printf("%d\n", (*stack)->n);
}
