#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

typedef struct node node;

node *
sll_create(void)
{
	node *head = malloc(sizeof(node));

	if (head == NULL)
		return NULL;

	head->next = NULL;
	return head;
}

void
sll_free(node *head)
{
	if (head == NULL)
		return;

	if (head->next != NULL)
		sll_free(head->next);

	free(head);
}

int
sll_pushfront(struct node *head, int value)
{
	if (head == NULL)
		return 1;

	node *new = malloc(sizeof(node));
	if (new == NULL)
		return 1;
	new->value = value;
	new->next = head->next;
	head->next = new;
	return 0;
}

int
sll_pushback(struct node *head, int value)
{
	if (head == NULL)
		return 1;

	node *last;
	node *new;

	for (last = head; last->next != NULL; last = last->next);

	new = malloc(sizeof(node));
	if (new == NULL)
		return 1;
	new->value = value;
	new->next = NULL;
	last->next = new;

	return 0;
}

void
sll_push(node *head, int index, int value)
{
	if (head == NULL)
		return;
	node *tmp = head->next;
	node *new = malloc(sizeof(node));
	if (new == NULL)
		return;
	new->value = value;

	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp->value == index) {
			new->next = tmp->next;
			tmp->next = new;
			return;
		}
	}
}

void
sll_popfront(node *head)
{
	if (head == NULL || head->next == NULL)
		return;

	node *tmp = head->next;
	head->next = tmp->next;
	free(tmp);
}

void
sll_popback(node *head)
{
	if (head == NULL)
		return;

	node *last;
	for (last = head; last->next != NULL; last = last->next);
	last = NULL;
}

void
sll_pop(node *head, int index)
{
	if (head == NULL)
		return;

	node *tmp;
	for (node *i = head->next; i->next != NULL; i = i->next) {
		if (i->value == index) {
			tmp = i->next;
			i->next = tmp->next;
			free(tmp);
			return;
		}
	}
}

int
sll_length(node *head)
{
	int length = 0;
	for (node *tmp = head; tmp != NULL; tmp = tmp->next, length++);

	return length;
}

void
sll_print(struct node *head)
{
	for (node *i = head->next; i != NULL; i = i->next)
		printf("%d\n", i->value);
}
