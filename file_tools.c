#include "monty.h"

/**
 * open_f - simply opens a file
 * @file_one: the namepath of the file
 * Return: void
 */

void open_f(char *file_one)
{
	FILE *fd = fopen(file_one, "r");

	if (file_one == NULL || fd == NULL)
		ero(2, file_one);

	read_f(fd);
	fclose(fd);
}


/**
 * read_f - reads a file
 * @fd: pointer to the descriptor of file
 * Return: void
 */

void read_f(FILE *fd)
{
	int ln_number, formt = 0;
	char *buff = NULL;
	size_t length = 0;

	for (ln_number = 1; getline(&buff, &length, fd) != -1; ln_number++)
	{
		formt = parse_l(buff, ln_number, formt);
	}
	free(buff);
}


/**
 * parse_l - Separates each line into tokens to determine
 * which function to call
 * @buff: a line from the file
 * @l_numb: the line number
 * @formt:  storage format. in case 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. and 1 if queue.
 */

int parse_l(char *buff, int l_numb, int formt)
{
	char *opcd, *val;
	const char *delim = "\n ";

	if (buff == NULL)
		ero(4);

	opcd = strtok(buff, delim);
	if (opcd == NULL)
		return (formt);
	val = strtok(NULL, delim);

	if (strcmp(opcd, "stack") == 0)
		return (0);
	if (strcmp(opcd, "queue") == 0)
		return (1);

	find_fun(opcd, val, l_numb, formt);
	return (formt);
}

/**
 * find_fun - finds the appropriate function for the opcode
 * @opcd: opcode
 * @val: argument of opcode
 * @formt:  storage format. If 0 Nodes will be entered as a stack.
 * @ln_num: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_fun(char *opcd, char *val, int ln_num, int formt)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_t_stack},
		{"pall", prnt_stack},
		{"pint", print_topn},
		{"pop", pop_topn},
		{"Nop", Nop},
		{"swap", Swap_nodes},
		{"add", Add_nodes},
		{"sub", Sub_nodes},
		{"div", Div_nodes},
		{"mul", Mul_nodes},
		{"mod", Mod_nodes},
		{"pchar", prnt_char},
		{"pstr", print_stri},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcd[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcd, func_list[i].opcode) == 0)
		{
			call_func(func_list[i].f, opcd, val, ln_num, formt);
			flag = 0;
		}
	}
	if (flag == 1)
		ero(3, ln_num, opcd);
}


/**
 * call_func - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_func(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flg;
	int i;

	flg = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flg = -1;
		}
		if (val == NULL)
			ero(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				ero(5, ln);
		}
		node = cr_node(atoi(val) * flg);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_q(&node, ln);
	}
	else
		func(&head, ln);
}
