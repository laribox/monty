#include "monty.h"
/**
 * add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
*/
void add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, n;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(pa.file);
		free(pa.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	n = h->n + h->next->n;
	h->next->n = n;
	*head = h->next;
	free(h);
}
