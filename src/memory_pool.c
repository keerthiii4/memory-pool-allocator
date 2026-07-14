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

void memory_pool_free(void *ptr){
if(ptr == NULL){
return;
}
MemoryBlock *block = (MemoryBlock *)ptr;
block->next = free_list;
free_list = block;
}

void memory_pool_print_status(void){
MemoryBlock *current = free_list;
int free_blocks = 0;

printf("Memory Pool Status:\n");
printf("Total Blocks: %d\n", BLOCKS);
printf("Free block addresses\n");

while(current != NULL){
printf("%p\n", (void *)current);
free_blocks++;
current=current->next;
}
printf("Free Blocks:%d\n", free_blocks);
printf("Allocated Blocks:%d\n", BLOCKS-free_blocks);
}
