#include "monty.h"

/**
 * digit_check - checks for non-digit values in a string
 * @n: number to bec inspected for non-digit values
 *
 * Return: TRUE or FALSE
 */
int digit_check(char *n)
{
	int i;

	for (i = 0; n[i] != '\0'; i++)
		if (isdigit(n[i]) == 0)
			return (0);

	return (1);
}
