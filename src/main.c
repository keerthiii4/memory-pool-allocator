#include<stdio.h>
#include "memory_pool.h"

int main(void)
{
printf("=========================================\n");
printf("          Memory Pool Allocator          \n");
printf("=========================================\n");
printf("Initializing memory pool.....\n");
memory_pool_init();
printf("Memory Pool Initialized sucessfully\n");
printf("Allocating block 1...\n");
void *block1 = memory_pool_allocate();
if(block1 != NULL){
printf("Allocated block 1 successfully\n");
}
else{
printf("Allocation failed!\n");
}
printf("Memory pool status:\n");
memory_pool_print_status();

printf("Freeing block 1\n");
memory_pool_free(block1);
printf("block 1 freed successfully\n");

printf("Memory pool status after freeing\n");
memory_pool_print_status();

printf("Demo done successfully!\n");

return 0;
}
