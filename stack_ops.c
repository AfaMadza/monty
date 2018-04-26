# include "monty.h"
/**
 * _push - pushes an element to the stack
 * @stack: double pointer to head of stack
 * @line_num: line number from file
 *
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_num)
{
	stack_t *new = NULL;
	char *num;

	if (glob_str->input[1] == NULL)
	{
		printf("L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
		num = glob_str->input[1];

	if (digit_check(num) == 1)
	{
		new = malloc(sizeof(stack_t));
		if (new == NULL)
		{
			printf("Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (new)
	{
		new->n = atoi(num);
		new->prev = NULL;
		new->next = *stack;
		*stack = new;
	}
}
/**
 * _pall - prints a doubly linked list
 * @stack: double pointer to list head
 * @line_num: the line number from file
 * Return: None
 */
void _pall(stack_t **stack, unsigned int line_num)
{
	stack_t *current;

	(void)line_num;
	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * _pint - prints the value at the top of the stack;
 * @stack: double pointer to list head
 * @line_num: the line number from file
 */
void _pint(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;

	line_num = glob_str->line_no;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}
/**
 * _pop - removes the value at the top of the stack;
 * @stack: double pointer to list head
 * @line_num: the line number from file
 */
void _pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	line_num = glob_str->line_no;
	if (!stack || !*stack)
	{
		printf("L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
/**
 * _swap - swaps the top two values at the top of the stack;
 * @stack: double pointer to list head
 * @line_num: the line number from file
 */
void _swap(stack_t **stack, unsigned int line_num)
{
	int tmp;

	line_num = glob_str->line_no;
	if (!stack || !*stack || !(*stack)->next)
	{
		printf("L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
