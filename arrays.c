#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
typedef struct {
	int* items; 
	int capacity;
}intArray; 

intArray createIntArray(int n) {
	intArray arr = {
		.capacity = n,
		.items = malloc(sizeof(int) * n)
	};
	for (int i = 0; i < arr.capacity; i++) {
	arr.items[i] = 0; 
	}
	return arr;
}

int intArrayGet(intArray arr, int index) {
	if (arr.capacity > index) {
		return arr.items[index];
	}
	raise(SIGTRAP);
}

void intArrayPut(intArray* arr, int index, int data) {
	if (arr->capacity > index) {
		arr->items[index] = data;
	}
	else {
		// There isint enough space in this array
		int deficit = index +1;
		arr->items = realloc(arr->items, deficit * sizeof(int));
		arr->capacity = deficit;
		if (arr->items == NULL) {
			raise(SIGTRAP);
		}

		// Now insert it at the desired index
		arr->items[index] = data;
	}
}
void destryArray(intArray arr) {
	free(arr.items);
}
int main() {
	intArray arr = createIntArray(5); 
	intArrayPut(&arr, 1325, 20);
	destryArray(arr);	
}
