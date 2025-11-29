#ifndef crox_memory_h
#define crox_memory_h

#include "common.h"

#define GROW_CAPACITY(capacity) \
  ((capacity) < 8 ? 8 : (capacity) * 2)


/*
 macro allocates more memory for an array 
 it typecasts the resulting void* back to a pointer of the right type.
*/
#define GROW_ARRAY(type, pointer, oldCount, newCount) \
  (type*)reallocate(pointer, sizeof(type) * (oldCount), \
  sizeof(type) * (newCount))

/*
* macro frees the memory by passing newsize as 0 to reallocate 
*/
#define FREE_ARRAY(type, pointer, oldCount) \
  reallocate(pointer, sizeof(type) * (oldCount), 0)

void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif
