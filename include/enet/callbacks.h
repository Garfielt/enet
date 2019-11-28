/** 
 @file  callbacks.h
 @brief ENet callbacks
*/
#ifndef __ENET_CALLBACKS_H__
#define __ENET_CALLBACKS_H__

#include <stdlib.h>

typedef struct _ENetCallbacks
{
    void * (ENET_CALLBACK * malloc) (size_t size, const char* file, int line);
    void (ENET_CALLBACK * free) (void * memory, const char* file, int line);
    void (ENET_CALLBACK * no_memory) (void);
} ENetCallbacks;

/** @defgroup callbacks ENet internal callbacks
    @{
    @ingroup private
*/
extern void * enet_malloc_raw (size_t, const char*, int);
extern void   enet_free_raw (void *, const char*, int);

/** @} */

#endif /* __ENET_CALLBACKS_H__ */

