#include <stdio.h>

int main(){
        int thing1[3] =                 {1, 2, 3};

        int thing2[3][3] =              {
                                        {4, 5, 6},
                                        {7, 8, 9},
                                        {10, 11, 12}
                                        };

        int thing3[3][3][3] = {
                                {
                                        {10,20,30},
                                        {40,50,60},
                                        {70,80,90},
                                },
                                {
                                        {11,22,33},
                                        {44,55,66},
                                        {77,88,99},
                                },
                                {
                                        {12,23,34},
                                        {45,56,67},
                                        {78,89,90}
                                }                                
                              };
 
        printf("thing1=%p &thing1=%p\n", thing1, &thing1);
        printf("thing2=%p &thing2=%p\n", thing2, &thing2);
        printf("thing3=%p &thing3=%p\n\n", thing3, &thing3);

        printf("thing1=%p &thing1=%p\n", thing1+1, &thing1+1);
        printf("thing2=%p &thing2=%p\n", thing2+1, &thing2+1);
        printf("thing3=%p &thing3=%p\n", thing3+1, &thing3+1);
        return 0;
}
