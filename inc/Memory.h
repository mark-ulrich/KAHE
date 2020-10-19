#ifndef __MEMORY_H__
#define __MEMORY_H__

#include "Types.h"

/**
 * A platform-independent simple malloc wrapper.
 *
 * NOTE: This is a wrapper around a platform-specific, malloc-like
 * allocator. This *IS NOT* a custom implementation of an allocator.
 */
void*
KMalloc(U64 size);

#endif // !__MEMORY_H__