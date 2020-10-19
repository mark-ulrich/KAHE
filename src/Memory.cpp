#include <stdlib.h>

#include "Memory.h"

void*
KMalloc(U64 size)
{
  // We'll keep this *very* simple for now: just call malloc
  return malloc(size);
}
