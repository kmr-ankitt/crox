#include<stdlib.h>
#include "memory.h"

/*
  * it reallocates memory block
  * if newSize is zero, then frees the memory block.
  * if oldSize is zero, realloc behaves like malloc.
  * if both oldSize and newSize are non-zero, resizes the memory block.
  * 
  * if the memory block just after is not available then 
  * realloc allocates a new memory block and copies the data 
  * from old block to new block.
  *
  * if not enough memory is available, exits the program with code 1.
*/
void* reallocate(void* pointer, size_t oldSize, size_t newSize){

  if(newSize == 0){
    free(pointer);
    return NULL;
  }

  void* result = realloc(pointer, newSize);
  
  if(result == NULL)
    exit(1);

  return result;
}
