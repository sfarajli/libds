#ifndef __LIB_DS__
#define __LIB_DS__

#include <sys/types.h>

typedef struct {
	size_t capacity;
	size_t used;
	int * arr;
} arrent;

typedef struct node {
	int value;
	struct node *next;
} node;

/* dynamic array */
int arr_init(arrent *arr);
void arr_free(arrent *arr);
int arr_push(arrent *arr, int value);
int arr_pop(arrent *arr, int *value);

/* linked list */
node *sll_init(void);
void sll_free(node *head);
int sll_pushfront(struct node *head, int value);
int sll_pushback(struct node *head, int value);
void sll_push(node *head, int index, int value);
void sll_popfront(node *head);
void sll_popback(node *head);
void sll_pop(node *head, int index);
int sll_length(node *head);
void sll_print(struct node *head);

/* stack */
node *stack_init(void);
void stack_free(node *);
int stack_push(node **head, int value);
int stack_pop(node **head);
void stack_print(struct node *head);

#endif
