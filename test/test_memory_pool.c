#include "memory_pool.h"
#include <stdio.h>
int main(void){
memory_pool_init();
void *ptr=memory_pool_allocate();
if(ptr != NULL){
printf("Memory allocation sucess\nThe allocated memory is %p\n",ptr);
}
else{
printf("allocation failed\n");
}
return 0;
}
