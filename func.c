#include <stdio.h>

void *r;
int topType=0; // 0はnull, 1は数値ポインタ, 2はコードポインタ
void *code;

int registers()
{
    return *(int *)r;
}

void setNumber(int *n)
{
    topType = 1;
    r = (void*)n;
}

void dumpCode(void *code)
{
    topType = 2;
    r = code;
    return r;
}

void* returnNull()
{
    return NULL;
}

int main(void)
{
    int a = 10;
    setNumber(&a);
    printf("%d", registers());
    return main;
}
