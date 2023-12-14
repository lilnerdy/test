#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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
	void (*f)(stack_t **stack, unsigned int l_numb);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void open_f(char *file_one);
int parse_l(char *buff, int l_numb, int formt);
void read_f(FILE *);
int len_chars(FILE *);
void find_fun(char *, char *, int, int);

/*Stack operations*/
stack_t *cr_node(int n);
void fr_nodes(void);
void prnt_stack(stack_t **, unsigned int);
void add_t_stack(stack_t **, unsigned int);
void add_to_q(stack_t **, unsigned int);

void call_func(op_func, char *, char *, int, int);

void print_topn(stack_t **, unsigned int);
void pop_topn(stack_t **, unsigned int);
void Nop(stack_t **, unsigned int);
void Swap_nodes(stack_t **, unsigned int);

/*Math operations with nodes*/
void Add_nodes(stack_t **, unsigned int);
void Sub_nodes(stack_t **, unsigned int);
void Div_nodes(stack_t **, unsigned int);
void Mul_nodes(stack_t **, unsigned int);
void Mod_nodes(stack_t **, unsigned int);

/*String operations*/
void prnt_char(stack_t **, unsigned int);
void print_stri(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*Error hanlding*/
void ero(int error_cd, ...);
void more_ero(int error_cd, ...);
void string_ero(int error_cd, ...);
void rotr(stack_t **, unsigned int);

#endif
