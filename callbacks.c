/** 
 @file callbacks.c
 @brief ENet callback functions
*/
#define ENET_BUILDING_LIB 1
#include "enet/enet.h"

static ENetCallbacks callbacks = { malloc, free, abort };

int
enet_initialize_with_callbacks (ENetVersion version, const ENetCallbacks * inits)
{
   if (version < ENET_VERSION_CREATE (1, 3, 0))
     return -1;

   if (inits -> malloc != NULL || inits -> free != NULL)
   {
      if (inits -> malloc == NULL || inits -> free == NULL)
        return -1;

      callbacks.malloc = inits -> malloc;
      callbacks.free = inits -> free;
   }
      
   if (inits -> no_memory != NULL)
     callbacks.no_memory = inits -> no_memory;

   return enet_initialize ();
}

ENetVersion
enet_linked_version (void)
{
    return ENET_VERSION;
}
           
void *
enet_malloc_raw (size_t size, const char* file, int line)
{
   void * memory = callbacks.malloc (size, file, line);

   if (memory == NULL)
     callbacks.no_memory ();

   return memory;
}

void
enet_free_raw (void * memory, const char* file, int line)
{
   callbacks.free (memory, file, line);
}

