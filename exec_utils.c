#include "monty.h"
/**
 * find_op - function pointer to find desired operation based on input
 * @void: void
 * Return: desired function.
 */
void (*find_op(void))(stack_t **stack, unsigned int line_num)
{
	char *input_op;
	instruction_t *i;
	static instruction_t instructions[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"swap", _swap}, {"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	i = instructions;
	input_op = glob_str->input[0];

	while (i->opcode && strncmp(i->opcode, input_op, strlen(input_op)))
		i++;

	if (!i->f)
	{
		printf("L%d: unknown instruction %s\n",
		       glob_str->line_no, input_op);
		exit(EXIT_FAILURE);
	}
	return (i->f);
}
/**
 * parse_args - parses line/getline into input global variable
 * @line: input line
 *
 * Return: void
 */

int parse_args(char *line)
{
	char *delm = " \t\n", *s;
	int len, i;

	s = glob_str->line;
	len = strlen(s);

	for (i = 0; s[i] == delm[0] || s[i] == delm[1] || s[i] == delm[2]; i++)
		;
	if (i == len)
		return (EXIT_FAILURE);

	glob_str->input[0] = strtok(line, delm);

	if (glob_str->input[0][0] == '#')
		return (EXIT_FAILURE);

	glob_str->input[1] = strtok(NULL, delm);

	return (EXIT_SUCCESS);
}
