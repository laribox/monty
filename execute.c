#include "monty.h"

/**
 * parse_line - parses a line of Monty bytecode
 * @content: line content
 * @op: pointer to store the opcode
 * @arg: pointer to store the argument
 * Return: 1 if parsing succeeded, 0 otherwise
 */
int parse_line(char *content, char **op, char **arg)
{
	*op = strtok(content, " \n\t");
	if (*op && (*op)[0] == '#')
		return (0);
	*arg = strtok(NULL, " \n\t");
	return (*op != NULL);
}

/**
 * execute_opcode - executes the parsed opcode
 * @op: parsed opcode
 * @arg: parsed argument (if any)
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: pointer to monty file
 */
void execute_opcode(char *op, char *arg, stack_t **stack,
		unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", push},
		{"pall", pall}, {"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_s},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}
	};
	unsigned int i = 0;

	while (opst[i].opcode)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			if (opst[i].f == push && arg == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", counter);
				fclose(file);
				free_stack(*stack);
				exit(EXIT_FAILURE);
			}
			opst[i].f(stack, counter);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
	fclose(file);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * execute - executes the opcode
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: pointer to monty file
 * @content: line content
 * Return: no return
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	char *op, *arg;

	if (!parse_line(content, &op, &arg))
		return (0);

	execute_opcode(op, arg, stack, counter, file);
	return (0);
}
