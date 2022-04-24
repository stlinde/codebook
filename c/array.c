#include <stdio.h>

/*
* Implementation of array datastructure.
* The time complexity should be:
*   O(1) to add or remove at end (amortized for allocation for more space), index, or update.
*   O(n) to insert or remove elsewhere
*
* The space complexity should be:
*   Contiguous in memory, so proximity helps performance.
*   Space neede = (array_capacity, which is >= n) * size of item. Thus O(n)
*
* The array should be allocated wihtout using built-in array functionalities.
* This can be done using pointers.
*/

void new_array(size_t item_size) {
  // Must allocate memory.
  // Start with capacity of 16, use power of 2.
  int *array = malloc(item_size * 16);
}

void free_array() {
  free(array);
}


void size() {
  // Number of items.
}

void capacity() {
  // Number of items the array can hold.
}

void is_empty() {
  // Checks if the array is empty.
}

void at(index) {
  // Returns item at given index, error if index is out of bounds.
}

void push(item) {
  // Push item onto the array - appending the item.
}

void insert(item, index) {
  // Insert the item into the array at given location. 
}

void prepend(item) {
  // Inserts item in beginning of array.
}

void pop() {
  // Remove item from the end and returns value.
}

void delete(index) {
  // Deletes the item at index shifting all elements left.
}

void remove(item) {
  // Looks for value and removes index holding it (even if multiple values).
}

void find(item) {
  // Looks for value and returns first index with that value, -1 if not found.
}

void resize(new_capacity) {
  // Private function.
  // When reaching max capacity, resize to double the size.
  // When popping an item, if size is 1/4 of capacity resize to half.
}
