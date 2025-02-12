#include <stdio.h>

void* r;
int (*e)(void);

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

int setRegisters(int a)
{
    return r = a;
}

void setFunc(int (*func)(void))
{
    e = func;
    return e;
}

int callFunc()
{
    r = e();
    return r;
}

int returnNull()
{
    return NULL;
}

int main(void)
{
    testAll();
    initRegisters();
    initEnvironments();
    printf("register r = %d\n", registers());
    printf("environments e = %x\n", environments());
    setRegisters(10);
    setFunc(&returnNull);
    printf("register r = %d\n", registers());
    printf("environments e = %x\n", environments());
    callFunc();
    printf("register r = %d\n", registers());
    printf("environments e = %x\n", environments());
    printf("新鮮な無 %d\n", returnNull());
    return 0;
}

int testAll()
{
    int pass=0;
    int error=0;
    void (*testFunc[])(void) = {&registers, &returnNull, &environments};
    void *testDataList[][3] = {{10, 10, 1}, {NULL, NULL, 0}, {NULL, NULL, 0}, NULL};
    int testFuncLength = 3;
    for(int n=0;n<testFuncLength;n++){
        if (1 == test(testFunc[n], testDataList[n][0], testDataList[n][1], testDataList[n][2]))
        {
            pass++;
            printf("pass\n");
        } else {
            error++;
            printf("error\n");
        }
    }
    printf("test pass : %d, error : %d\n", pass, error);
    return 0;
}

int test(void *(*func)(void), void* checkValue, void* registerValue, void* type_p)
{
    printf("checkValue = %d\n", (int*)checkValue);
    printf("registerValue = %d\n", (int*)registerValue);
    printf("return %d\n", func());
    int type = (int*)type_p;
    printf("type = %d\n", type);
    if(0 == type){
            return NULL == func();
    }else if(1 == type){
            r = registerValue;
            int v = (int*)checkValue;
            int a = func();
            printf("test %d == %d\n", v, a);
            return v == a;
    }
}
