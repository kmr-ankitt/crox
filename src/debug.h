#ifndef crox_debug_h
#define crox_debug_h

#include "chunk.h"

void diassembleChunk(Chunk* chunk, const char* name);
int diassembleInstruction(Chunk* chunk, int offset);

#endif
