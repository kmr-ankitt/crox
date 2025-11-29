#include "chunk.h"
#include "memory.h"
#include <stdint.h>

/*
 * initializes a dynamically allocated chunk structure
 */
void initChunk(Chunk* chunk){
  chunk->capacity = 0;
  chunk->count = 0;
  chunk->code = NULL;
}


/*
* writes a byte to chunk's array
* if current capacity is insufficient
* - grows the array capacity 
* else 
*  simply adds byte to the array
*/
void writeChunk(Chunk *chunk, uint8_t byte){
  if(chunk->capacity < chunk->count + 1) {
    int oldCapacity = chunk->capacity;
    chunk->capacity = GROW_CAPACITY(oldCapacity);
    chunk->code = GROW_ARRAY(
      uint8_t,
      chunk->code,
      oldCapacity,
      chunk->capacity
    );
  }

  chunk->code[chunk->count] = byte;
  chunk->count++;
}

/*
 * ceallocate all the memory and then zero out the fields.
*/
void freeChunk(Chunk* chunk){
  FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
  initChunk(chunk);
}
