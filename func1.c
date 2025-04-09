#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    NOTYPE,
    NUMBER,
    STRING,
    FUNCTION,
    TOKEN
} TYPE;

typedef enum
{
    INITE,
    ENV,
    INITR,
    REG,
    SETR,
    SETF,
    CALL,
    CNULL,
    EVAL
} CODE;

void* arg;
void* r;
int (*e)(void);
CODE c;
TYPE type=NOTYPE;

void* initEnvironments()
{
    e = NULL;
    return e;
}

void* environments()
{
    return e;
}

void* initRegisters()
{
    r = NULL;
    return r;
}

void* registers()
{
    return r;
}

void* setRegisters()
{
    return r = (int)arg;
}

void* setFunc()
{
    e = (int (*)())arg;
    return e;
}

void* callFunc()
{
    r = e();
    return r;
}

void* returnNull()
{
    return NULL;
}

int error(char* message)
{
    printf(message);
    return -1;
}

void eval()
{
    switch ((CODE)c)
    {
        case INITE: initEnvironments(); break;
        case ENV: environments(); break;
        case INITR: initRegisters(); break;
        case REG: registers(); break;
        case SETR: setRegisters(); break;
        case SETF: setFunc(); break;
        case CALL: callFunc(); break;
        case CNULL: returnNull(); break;
        case EVAL: eval(); break;
        default: error("コードがありません");
    }
}

void convert()
{
    switch ((TYPE)arg)
    {
        case NOTYPE: error("レジスターが初期状態です"); break;
        case NUMBER:
            if (STRING==type)
            {
                r = atoi(r);
                type = NUMBER;
            } else {
                error("数字に変換出来ません");
            };
            break;
        case STRING:
            if (NUMBER==type) {
                char* s = (char*)malloc(sizeof(char) * 256);
                sprintf(s, "%d", (int)r);
                r = s;
                type = STRING;
            } else if (STRING!=type) {
                error("文字列に変換出来ません");
            };
            break;
        case FUNCTION:
            if (STRING==type) {
                // e = loadFunction(r);
                // type = FUNCTION;
                error("まだ実装されてません");
            } else {
                error("文字列リテラル以外は関数になりません");
            }
        case TOKEN:
            if (NUMBER==type) {
                c = (CODE)r;
                type = TOKEN;
            } else if (STRING==type) {
                // c = tokenize(r);
                // type = CODE;
                error("まだ実装してません");
            } else {
                error("型エラー");
            };
            break;
        default: error("型エラー"); break;
    }
}

int main(void)
{
//    testAll();
    c = INITR;
    eval();
    printf("code c = %d\n", c);
    printf("register r = %d\n", (int)registers());
    printf("environments e = %p\n", environments());
    c = INITE;
    eval();
    printf("code c = %d\n", c);
    printf("register r = %d\n", (int)registers());
    printf("environments e = %p\n", environments());
    arg = 10;
    c = SETR;
    eval();
    printf("code c = %d\n", c);
    printf("register r = %d\n", (int)registers());
    printf("environments e = %p\n", environments());
    arg = &returnNull;
    c = SETF;
    eval();
    printf("code c = %d\n", c);
    printf("register r = %d\n", (int)registers());
    printf("environments e = %p\n", environments());
    c = CALL;
    eval();
    printf("code c = %d\n", c);
    printf("register r = %d\n", (int)registers());
    printf("environments e = %p\n", environments());
    printf("新鮮な無 %p\n", returnNull());
    return 0;
}

/**
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
    int type = (int)type_p;
    printf("type = %d\n", type);
    if(0 == type){
            return NULL == func();
    }else if(1 == type){
            r = registerValue;
            int v = (int)checkValue;
            int a = func();
            printf("test %d == %d\n", v, a);
            return v == a;
    }
}
**/
