#ifndef MONTY_H
#define MONTY_H

/*Standard Library Headers*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>

/*Structs*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * glob_strucs - a struct containing structs and variables.
 * @file_name: the filename from argv[1].
 * @stack_pt: pointer to stack.
 * @input: parsed lines from file.
 * @line: input line received from getline function.
 * @line_no: the line number in file.
 * @file: the input file containing bytecode.
 */
typedef struct glob_strucs
{
	char *file_name;
	stack_t *stack_pt;
	char **input;
	char *line;
	unsigned int line_no;
	FILE *file;
} glob_struct;

/*Global Variable*/
extern glob_struct *glob_str;
glob_struct *glob_str;

/*Main Functions*/
int make_glob_str(void);
void (*find_op(void))(stack_t **stack, unsigned int line_no);
int parse_args(char *line);

/*Utility Functions*/
int digit_check(char *n);

/*Memory Manipulation*/
void free_stack_pt(void);
void free_final(void);

/*Stack Operations*/
void _push(stack_t **stack, unsigned int line_no);
void _pall(stack_t **stack, unsigned int line_no);
void _pint(stack_t **stack, unsigned int line_no);
void _pop(stack_t **stack, unsigned int line_no);
void _swap(stack_t **stack, unsigned int line_no);

/*Stack Operations 1*/
void _add(stack_t **stack, unsigned int line_no);
void _nop(stack_t **stack, unsigned int line_no);

#endif
