#include <stdio.h>
#include <stdlib.h>

void g()
{
    printf("now inside g()!\n");
    fflush(stdout);
}


void f()
{   
  int i;
  void * buffer[1];
  printf("now inside f()!\n");
    fflush(stdout);
  // can only modify this section
  // cant call g(), maybe use g (pointer to function)

  // place the address of g all over the stack:
  for (i=0; i<10; i++)
     buffer[i] = (void*) g;

  // and goodbye..
}

int main (int argc, char *argv[])
{
    f();
    return 0;
}