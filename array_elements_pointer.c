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

/* k is a pointer to an array of size 3*/                              
        int (*k)[3] = &thing1; 
/* p is a pointer to an array of size 3 or size 3*/   
        int (*p)[3][3] = &thing2;
/* c is a pointer to an array of size 3 of size 3 of size 3*/           
        int (*c)[3][3][3] = &thing3;

/*m is a pointer to first element of array*/
        int *l = thing1; 
/* m is a pointer to an array of size 3*/           
        int (*m)[3] = thing2;
/* k is a pointer to an array of size 3 of size 3*/           
        int (*n)[3][3] = thing3;



/*------------------------------------------------*/
        printf("%d\n", *( (*p)[0] ));
        printf("%d\n", *( (*p)[1] ));
        printf("%d\n\n", *( (*p)[2] ));
        
        printf("%d\n", *( (*p)[0] +1 ));
        printf("%d\n", *( (*p)[1] +1 ));
        printf("%d\n\n", *( (*p)[2] +1 ));
/*------------------------------------------------*/        
        printf("%d\n", (*m)[0]);
        printf("%d\n", (*(m+1))[0]);
        printf("%d\n\n", (*(m+2))[0]);

        printf("%d\n", (*n)[0][0]);
        printf("%d\n", (*(n+1))[0][0]);
        printf("%d\n", (*(n+2))[0][0]);
         
        return 0;
}
