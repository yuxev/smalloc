#include "smalloc.h"

void    *smalloc(int size)
{
  void *p = sbrk(0);
  void *request = sbrk(size);
  if (request == (void*) -1) {
    return NULL; // sbrk failed.
  } else {
    assert(p == request); // Not thread safe.
    return p;
  }
}

int main(void)
{
    void *p = smalloc(10);
}