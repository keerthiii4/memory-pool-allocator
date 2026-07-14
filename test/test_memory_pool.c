#include "memory_pool.h"
#include <stdio.h>
int main(void){
memory_pool_init();
void *ptr1 = memory_pool_allocate();
void *ptr2 = memory_pool_allocate();

printf("Allocated block1: %p\n", ptr1);
printf("Allocated block2: %p\n", ptr2);

memory_pool_free(ptr1);

printf("Block 1 freed sucessfully\n");

void *ptr3 = memory_pool_allocate();
printf("Again allocated %p memory\n", ptr3);

/*if(ptr != NULL){
printf("Memory allocation sucess\nThe allocated memory is %p\n",ptr);
}
else{
printf("allocation failed\n");
}*/
return 0;
}
