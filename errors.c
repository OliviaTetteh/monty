#include "monty.h"

/**
 * more_err - handles errors.
 * @error_code: The error codes are the following:
 * (6) ~> When the stack it empty for pint.
 * (7) ~> When the stack it empty for pop.
 * (8) ~> When stack is too short for operation.
 * (9) ~> Division by zero.
 */
void more_err(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			printf("L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			printf("L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			printf("L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			printf("L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - handles errors.
 * @error_code: The error codes are the following:
 */
void string_err(int error_code, ...)
{
	va_list ag;
	int l_num;

	va_start(ag, error_code);
	l_num = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			printf("L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			printf("L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}