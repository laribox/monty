#include "monty.h"
/**
* free_stack - frees element of the stack
* @head: head of the stack
*/
void free_stack(stack_t *head)
{
	stack_t *s;

	s = head;
	while (head)
	{
		s = head->next;
		free(head);
		head = s;
	}
}
