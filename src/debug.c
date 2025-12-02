#include "chunk.h"
#include <stdio.h>
#include "debug.h"

/*
* it disassembles the entire chunk by iterating through each instruction
*/
void diassembleChunk(Chunk *chunk, const char *name){
  printf("== %s ==\n", name);

  for(int offset = 0; offset < chunk->count;){
    offset = diassembleInstruction(chunk, offset);
  }
}

static int simpleInstruction(const char* name, int offset){
  printf(" %s\n", name);
  return offset + 1;
}

/*
* offset shows where the instruction is located in the chunk
* disassembles a single instruction at given offset
* and returns the offset of the next instruction
*/
int diassembleInstruction(Chunk* chunk, int offset){
  printf("%04d", offset);

  uint8_t instruction = chunk->code[offset];
  switch(instruction){
    case OP_RETURN:
      return simpleInstruction("OP_RETURN", offset);
      break;
    default:
      printf("Unknown opcode %d\n", instruction);
      return offset + 1;
  }
}

