#include "monty.h"
/**
 * main - entry point to monty interpreter.
 * @argc: number of arguments.
 * @argv: double pointer to an array of arguments passed.
 * Return: 0 for success or EXIT_FAILURE upon failure.
 */
int main(int argc, char **argv)
{
	size_t n;
	void (*run_prog)(stack_t **stack, unsigned int line_num);

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	make_glob_str();
	glob_str->file_name = argv[1];
	glob_str->file = fopen(glob_str->file_name, "r");
	if(!glob_str->file)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&glob_str->line, &n, glob_str->file) > 0)
	{
		glob_str->line_no += 1;
		if (parse_args(glob_str->line) == EXIT_FAILURE)
			continue;
		run_prog = find_op();
		run_prog(&glob_str->stack_pt, glob_str->line_no);
	}
	free_final();
	return (0);
}
/**
 * make_glob_str - creates a global struct containing needed variables
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int make_glob_str(void)
{
	glob_str = malloc(sizeof(glob_struct));
	if (!glob_str)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	glob_str->input = malloc(sizeof(char *) * 3);
	if (!glob_str->input)
	{
		free(glob_str);
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	glob_str->stack_pt = NULL;
	glob_str->line = NULL;
	glob_str->line_no = 0;
	return (EXIT_SUCCESS);
}
