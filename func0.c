#include <stdio.h>

int r;
void (*e)(void);

void initEnvironments()
{
  e = NULL;
  return e;
}

void* environments()
{
  return e;
}

int initRegisters()
{
    r = 0;
    return r;
}

int registers()
{
    return r;
}

int returnNull()
{
    return NULL;
}

int main(void)
{
    initRegisters();
    initEnvironments();
    printf("register r = %d\n", registers());
    printf("environments e = %x\n", environments());
    printf("新鮮な無 %d\n", returnNull());
    return 0;
}
