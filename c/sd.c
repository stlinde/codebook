#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Array {
  int size;
  int capacity;
  int *data;
} Array;

// Explanation:
//    The function new_array returns a instance of the struct Array.
//    We first allocate memory to the array on the heap - with malloc.
Array new_array(size_t item_size) {
  // Declaring the new array.
  Array *array = malloc(sizeof(Array));

  array->size = 0;
  array->capacity = (int)item_size * 16;
  array->data = (int *)malloc(array->capacity);
  return *array;
}

// Function to remove and free the memory allocated to the array.
// Figure out how to free it from memory.
void remove_array(Array *array_pointer) {
  if (array_pointer != NULL) {
    free (array_pointer->data);
    free (array_pointer);
  }
}

// Returns the size of the array (current items).
int size(Array *array_pointer) {
  int size_array = array_pointer->size; 
  return size_array;
}

// Returns the capacity of the array.
int capacity(Array *array_pointer) {
  int capacity_array = array_pointer->capacity;
  return capacity_array;
}

void capacity_check(Array *array_pointer) {
  if (array_pointer->size == array_pointer->capacity) {
    array_pointer->data = (int *)realloc(array_pointer, array_pointer->capacity * 2); 
  }
}

// Checks if the array is empty
int is_empty(Array *array_pointer) {
  if (array_pointer->size == 0) {
    return 0;
  } else {
    return 1;
  }
}

void push(Array *array_pointer, int item) {
  *(array_pointer->data + array_pointer->size) = item;
  ++(array_pointer->size);
}

int* at(Array *array_pointer, int index) {
  int* item = (array_pointer->data + index);
  return item;
}

void insert(Array *array_pointer,int item, int index) {
  // Looping from the top till the index.
  int i = size(array_pointer) + 1;
  while (i >= index) {
    *(array_pointer->data + i + 1) = *(array_pointer->data +i);
    i--;
  }
  *(array_pointer->data + index) = item;
  ++(array_pointer->size);
}

void prepend(Array *array_pointer, int item) {
  insert(array_pointer, item, 0);
}

int pop(Array *array_pointer) {
  int* item = (array_pointer->data + array_pointer->size);
  *(array_pointer->data + array_pointer->size) = 0;
  --(array_pointer->size); 
  return *item;
}

int main() {
  Array arr1 = new_array(sizeof(int));
  push(&arr1, 12);
  push(&arr1, 31);
  push(&arr1, 3);
  insert(&arr1, 5, 1);
  prepend(&arr1, 1);
  int item = pop(&arr1);
  
  printf("Capacity of array: %d\n", item);
  printf("Capacity of array: %d\n", *at(&arr1, 0));
  printf("Capacity of array: %d\n", *at(&arr1, 1));
  printf("Capacity of array: %d\n", *at(&arr1, 2));
  printf("Capacity of array: %d\n", *at(&arr1, 3));
  printf("Capacity of array: %d\n", *at(&arr1, 4));
  return 0;
}
