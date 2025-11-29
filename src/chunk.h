#ifndef crox_chunk_h
#define crox_chunk_h

#include "common.h"

/* 
 * each instruction has one byte operation code(opcode).
 * it defines what kind of operations we're dealing with.
*/
typedef enum{
  OP_RETURN,
} OpCode;

/*
* chunk structure that holds bytecode and other data
*  - capacity: total allocated size for code array
*  - count: current number of bytes used in code array
*  - code: dynamic array of bytes representing bytecode
*/
typedef struct{
  int capacity;
  int count;
  uint8_t* code;
} Chunk;

void initChunk(Chunk* chunk);

void writeChunk(Chunk* chunk, uint8_t byte);

void freeChunk(Chunk* chunk);

#endif
