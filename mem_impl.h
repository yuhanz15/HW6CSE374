/* mem_impl.h is the header for private implementation of memory project
   The declarations in here are not needed by the user (bench), but rather are
   included in the back end implementation of the memory system.
*/

#ifndef MEM_IMPL_H_
#define MEM_IMPL_H_

#include <assert.h>
#include <inttypes.h>
#include <stdlib.h>

#define NODESIZE sizeof(freeNode)
#define MINCHUNK 16  // minimum size of a memory chunk in the list
#define BIGCHUNK 16000  // default very large amount to allocate.

// freeNode will hold the info about the block + pointer to the next node
typedef struct freeNode {
  uintptr_t size;  // useable memory, doesn't include freeNode
  struct freeNode* next;
} freeNode;

/* These global variables would usually be static globals in one module.
   However, to accommodate our separate files for utils and basic memory
   functions we are declaring them here.  They need to be initialized
*/
extern freeNode* freelist;
extern uintptr_t totalmalloc;

// other important stats values
extern uintptr_t totalfree;
extern uintptr_t blockfree;

/* Check for possible problems with the free list data structure.
   When called this function should use asserts to verify that the free
   list has the following properties:
   Blocks are ordered with strictly increasing memory addresses
   Block sizes are positive numbers and large than the minimum
   Blocks do not overlap
   Blocks are not touching
   If no errors are detected, this function should return silently. */
void check_heap();

/* Are there other helper functions that both getmem and freemem need?
   If so, declare them here. */

#endif  // MEM_IMPL_H_
