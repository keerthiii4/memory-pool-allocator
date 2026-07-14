#include "memory_pool.h"
#include <stdio.h>

#define BLOCK_SIZE 32
#define BLOCKS 8

static unsigned char memory_pool[BLOCK_SIZE*BLOCKS];

typedef struct MemoryBlock{
struct MemoryBlock *next;
}MemoryBlock;

static MemoryBlock *free_list = (MemoryBlock *)(memory_pool);

void memory_pool_init(void){
for(int i=0; i<BLOCKS; i++){
MemoryBlock *block=(MemoryBlock *)(memory_pool+(i*BLOCK_SIZE));
if(i==BLOCKS-1){
block->next=NULL;
}
else{
block->next=(MemoryBlock *)(memory_pool+((i+1) * BLOCK_SIZE));
}
}
//printf("Memory pool initialization ran sucessfully\n");
}

void *memory_pool_allocate(void){
if (free_list==NULL){
return NULL;
}
MemoryBlock *block = free_list;
free_list = free_list->next;

return (void *)block;
}
