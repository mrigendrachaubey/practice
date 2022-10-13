/*C program to reverse bits of a number */

#include <stdio.h>

unsigned int revBits(unsigned int data)
{
    unsigned char totalBits = sizeof(data) * 8;
    unsigned int revNum = 0, i, temp;

    for (i = 0; i < totalBits; i++) {
        temp = (data & (1 << i));
        if (temp)
            revNum |= (1 << ((totalBits - 1) - i));
    }

    return revNum;
}

void showbits(int value)
{
        unsigned int displaymask = 1 << 31;
        printf("%10u = ", value);
        for (unsigned int c = 1; c <=32;++c)
        {
                putchar(value & displaymask ? '1': '0');
                value <<= 1;
                if (c % 8 == 0)
                        putchar(' ');
        }
}

int main()
{
    unsigned int num = 0x4;
    showbits(num);
    printf("\n%u\n", revBits(num));
    return 0;
}
