#include "chunk.h"
#include "debug.h"

int main() {
  Chunk chunk;
  initChunk(&chunk);
  writeChunk(&chunk, OP_RETURN);
  diassembleChunk(&chunk, "test chunk");
  freeChunk(&chunk);
}
