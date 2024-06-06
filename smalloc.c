#include "smalloc.h"

void    *smalloc(int size)
{
  void *p = sbrk(0); // when we give the number 0 to sbrk it return the adress of the current top of the heap
  void *request = sbrk(size); // and here we increment the heap size by "size"
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