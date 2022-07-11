/*pass an array by reference*/
/*
int (*p)[]
(*p): p is 
[]: an array of
int: type of int

so reference of array can be taken like this,
p is an array of type of int
*/
#include <stdio.h>

void passbyref(int (*p)[])
{
	printf("%d ", (*p)[0]);
	printf("%d ", (*p)[1]);
	printf("%d ", (*p)[2]);
	printf("%d ", (*p)[3]);
	printf("\n");
}


int main(void)
{
	int exp[4] = {1, 2, 3, 4};
	passbyref(&exp);
	return 0;	
}