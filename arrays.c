#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
typedef struct {
	int* items; 
	int length; 
	int capacity;
}intArray; 

intArray createIntArray(int n) {
	intArray arr = {
		.length = n,
		.capacity = n,
		.items = malloc(sizeof(int) * n)
	};
	for (int i = 0; i < arr.length; i++) {
		arr.items[i] = 0; 
	}
	return arr;
}

int intArrayGet(intArray arr, int index) {
	if (arr.length > index) {
		return arr.items[index];
	}
	raise(SIGTRAP);
}

void intArrayPut(intArray arr, int index, int data) {
	if (arr.length > index) {
		arr.items[index] = data;
	}
	raise(SIGTRAP);
}
void destryArray(intArray arr) {
	free(arr.items);
}
int main() {
	intArray arr = createIntArray(5); 
	printf("%d", intArrayGet( arr, 3));
	destryArray(arr);	
}