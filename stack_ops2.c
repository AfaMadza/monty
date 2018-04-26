# include "monty.h"
/**
 * _add - adds the top two elements of a stack
 * @stack: double pointer to head of stack
 * @line_num: line number from file
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_num)
{
	int total = 0;

	line_num = glob_str->line_no;
	if (!stack || !*stack || !(*stack)->next)
	{
		printf("L%d: can't can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	total = (*stack)->n + (*stack)->next->n;
	_pop(stack, line_num);
	(*stack)->n = total;
}
/**
 * _nop - doesn't do anything
 * @stack: double pointer to list head
 * @line_num: the line number from file
 * Return: None
 */
void _nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}
