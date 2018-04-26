#include "monty.h"
/**
 * free_stack_pt - frees all memory allocated in stack
 *
 * Return: None
 */
void free_stack_pt(void)
{
	stack_t *tmp, *head;

	if (glob_str->stack_pt)
	{
		head = glob_str->stack_pt;

		while (head)
		{
			tmp = head->next;
			free(head);
			head = tmp;
		}
	}
}

/**
 * free_final - frees all memory assigned by malloc
 *
 * Return: None
 */
void free_final(void)
{
	if (glob_str != NULL)
	{
		if (glob_str->file != NULL)
			fclose(glob_str->file);
		if (glob_str->line != NULL)
			free(glob_str->line);
		if (glob_str->input != NULL)
			free(glob_str->input);
		free_stack_pt();
		free(glob_str);
	}
}
