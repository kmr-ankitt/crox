#ifndef crox_memory_h
#define crox_memory_h

#include "common.h"

#define GROW_CAPACITY(capacity) \
  ((capacity) < 8 ? 8 : (capacity) * 2)


/*
 macro typecasts the resulting void* back to a pointer of the right type.
*/
#define GROW_ARRAY(type, pointer, oldCount, newCount) \
  (type*)reallocate(pointer, sizeof(type) * (oldCount), \
  sizeof(type) * (newCount))

void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif
