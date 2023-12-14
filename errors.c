#include "monty.h"

/**
 * ero - Prints appropiate error messages determined by their error code.
 * @error_cd: The error codes are the following:
 * (1) => The user does provide no file or more than 1 file to the program.
 * (2) => The file given is not a file that can be opened or read.
 * (3) => The file provided includes an invalid instruction.
 * (4) => the case when the program is not able to malloc more memory.
 * (5) => the case when the parameter passed to the instruction "push" !int.
 * (6) => the case when the stack it empty for pint.
 * (7) => the case when the stack it empty for pop.
 * (8) => the case when stack is too short for operation.
 */
void ero(int error_cd, ...)
{
	va_list ag;
	char *opp;
	int line_numb;

	va_start(ag, error_cd);
	switch (error_cd)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			line_numb = va_arg(ag, int);
			opp = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_numb, opp);
			break;
		case 4:
			fprintf(stderr, "error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	fr_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_ero - handles errors.
 * @error_cd: The error codes are the following:
 * (6) => the case when the stack it empty for pint.
 * (7) => the case when the stack it empty for pop.
 * (8) => the case when stack is too short for operation.
 * (9) => Division by 0.
 */
void more_ero(int error_cd, ...)
{
	va_list ag;
	char *opp;
	int line_numb;

	va_start(ag, error_cd);
	switch (error_cd)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			line_numb = va_arg(ag, unsigned int);
			opp = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_numb, opp);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	fr_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_ero - basically handles them errors.
 * @error_cd: The actual error codes
 * (10) ~> The number inside a node is out of ASCII bounds.
 * (11) ~> empty stack.
 */
void string_ero(int error_cd, ...)
{
	va_list ag;
	int line_numb;

	va_start(ag, error_cd);
	line_numb = va_arg(ag, int);
	switch (error_cd)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_numb);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_numb);
			break;
		default:
			break;
	}
	fr_nodes();
	exit(EXIT_FAILURE);
}
