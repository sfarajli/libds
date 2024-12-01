#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "../libds.h"

node *
stack_init(void)
{
	node *head = NULL;
	return head;
}

int
stack_push(node **head, int value)
{
	node *new = malloc(sizeof(node));
	if (new == NULL)
		return 1;
	new->value = value;
	new->next = *head;
	*head = new;
	return 0;
}

int
stack_pop(node **head)
{
	if (*head == NULL)
		return INT_MIN;

	int result = (*head)->value;
	node *tmp = *head;
	*head = (*head)->next;
	free(tmp);
	return result;
}
void
stack_print(struct node *head)
{
	if (head == NULL)
		return;

	for (node *i = head; i != NULL; i = i->next)
		printf("%d\n", i->value);
}
