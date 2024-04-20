#include <stdio.h>
#include "dynarr.h"

void printDynamicArray(DynamicArray* arr) {
  for (int i = 0; i < arr->size; i++) {
    printf("%.2f ", arr->buffer[i]);
  }
  printf("\n");
}

int main(void) {
  printf("Executing tests \n");

  DynamicArray dynarr = init(2);

  printf("Initial capacity: %u\n", dynarr.capacity);
  printf("Initial size: %u\n", dynarr.size);

  pushBack(&dynarr, 10.0f);
  pushBack(&dynarr, 15.0f);
  printDynamicArray(&dynarr);

  push(&dynarr, 1, 77.0f);
  printDynamicArray(&dynarr);

  pushFront(&dynarr, 105.0f);
  pushFront(&dynarr, 11.0f);
  printDynamicArray(&dynarr);

  DynArrType secondElement = getElement(&dynarr, 1);
  printf("Second element: %.2f\n", secondElement);

  setElement(&dynarr, 10, 999.0f);
  printDynamicArray(&dynarr);

  DynArrType thirdElement = removeElement(&dynarr, 2);
  printf("Third element: %.2f\n", thirdElement);
  printDynamicArray(&dynarr);

  DynArrType firstElement = popFront(&dynarr);
  printf("First element: %.2f\n", firstElement);
  printDynamicArray(&dynarr);

  DynArrType lastElement = popBack(&dynarr);
  printf("Last element: %.2f\n", lastElement);
  printDynamicArray(&dynarr);

  release(&dynarr);
  float searchIndex = 105;
  printf("Index: %d\n", findIndex(&dynarr, searchIndex));

  return 0;
}