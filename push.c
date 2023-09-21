#include "monty.h"
/**
 * push - add node to the stack
 * @head: stack head
 * @counter: line_number
*/
void push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (pa.arg)
	{
		if (pa.arg[0] == '-')
			j++;
		for (; pa.arg[j] != '\0'; j++)
		{
			if (pa.arg[j] > 57 || pa.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(pa.file);
			free(pa.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(pa.file);
		free(pa.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(pa.arg);
	addnode(head, n);
}
