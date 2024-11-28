#include <stdlib.h>
#include <sys/types.h>

typedef struct {
	size_t capacity;
	size_t used;
	int * arr;
} arrent;

int
arr_init(arrent *arr)
{
	arr->arr = malloc(sizeof(int));
	if (arr->arr == NULL)
		return 1;
	arr->capacity = 1;
	arr->used = 0;
	return 0;
}

void
arr_free(arrent *arr)
{
	free(arr->arr);
}

int
arr_push(arrent *arr, int value)
{
	if (arr->capacity == arr->used) {
		arr->capacity *= 2;
		arr->arr = realloc(arr->arr, arr->capacity * sizeof(int));
		if (arr->arr == NULL)
			return 1;
	}

	arr->arr[arr->used] = value;
	arr->used++;
	return 0;
}

int
arr_pop(arrent *arr, int *value)
{
	if (arr->used != 0)
		arr->used--;
	else
		return 1;

	*value = arr->arr[arr->used];

	return 0;
}
