#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#incldue<stddef.h>

void memory_pool_init(void);
void *memory_pool_allocate(void);
void memory_pool_free(void *ptr);
void memory_pool_print_status(void);

#endif
