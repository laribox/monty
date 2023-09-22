#include "monty.h"
/**
 * swap - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void swap(stack_t **head, unsigned int counter)
{
	stack_t *tmp;
	int len = 0, n;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(pa.file);
		free(pa.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	n = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = n;
}
