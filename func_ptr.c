#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun1() { printf("Fun1\n"); }
void fun2() { printf("Fun2\n"); }

typedef struct pstring_t pstring_t;

struct pstring_t {
        char *chars;
        int (*length)(pstring_t *self);
};

int length(pstring_t *self) {
        return strlen((self)->chars);
}

pstring_t *initializeString(int n) {
        pstring_t *str = malloc(sizeof(pstring_t));

        str->chars = malloc(sizeof(char) * n);
        str->length = length;

        str->chars[0] = '\0'; //add a null terminator in case the string is used before any other initialization.

        return str;
}


void add(int a, int b)
{
        printf("Addition is %d\n", a+b);
}

void subtract(int a, int b)
{
        printf("Subtraction is %d\n", a-b);
}

void multiply(int a, int b)
{
        printf("Multiplication is %d\n", a*b);
}


void wrapper(void (*fun)())
{
        fun();
}

void fun(int a)
{
        printf("Value of a is %d\n", a);
}

void funn(int a)
{
        printf("Value of a is %d\n", a);
}

int main()
{
        //simple function pointer with function name
        void (*fun_ptr1)(int) = fun;
        //simple function pointer with function address
        void (*fun_ptr2)(int) = &funn;
        
        pstring_t *p = initializeString(30);
        strcpy(p->chars, "Hello");
        printf("\n%s %d\n", p->chars, p->length(p));

        // as an array of function pointers
        void (*fptr[])(int, int) = {add, subtract, multiply};
        unsigned int ch, a = 15, b = 10;
  
        fun_ptr1(10);
        (*fun_ptr2)(15);

        //as a wrapper to different functions
        wrapper(fun1);
        wrapper(fun2);

        printf("Enter Choice: 0 for add, 1 for subtract and 2 for multiply\n");
        scanf("%d", &ch);
  
        if (ch > 2) 
                return 0;
        //as an array of func pointer  
        (*fptr[ch])(a, b);
  
        return 0;
}
