#include <stdio.h>


int main(void)
#if 0 /* casting takes precedence and make address an unsigned long value https://en.cppreference.com/w/c/language/operator_precedence*/
{
        char thing[8];
        printf("%lu %lu\n", (unsigned long)thing, (unsigned long)&thing );
        printf("%lu %lu\n", (unsigned long)thing+1, (unsigned long)&thing+1);
        return 0;
}
#endif
#if 1
{
        char thing[8];
        printf("%lu %lu\n", thing, &thing );
        printf("%lu %lu\n", thing+1, &thing+1);
        return 0;
}
#endif
