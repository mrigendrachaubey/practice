/*
arr[row][column]
*/
#define ROW     4
#define COLUMN  3

#include <stdio.h>

int main(void)
{
        int i, j;
        int arr[ROW][COLUMN]={  {1,2,3}, /*ROW=0*/
                                {2,3,4}, /*ROW=1*/
                                {3,4,5}, /*ROW=2*/
                                {4,5,6}  /*ROW=3*/
                             };

        for(i=0; i<ROW; i++) {
                for (j=0; j<COLUMN; j++)
                        printf("%d ", arr[i][j]);
                printf("\n");
        }

        return 0;
}
