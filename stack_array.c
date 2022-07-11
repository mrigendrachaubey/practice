#include <stdio.h>

#define MAX_ENTRIES 10

int stack[MAX_ENTRIES] = {0};
int top = -1;


 void push (int value)
 {
	 printf("push\n");

	if(++top > MAX_ENTRIES)
		printf("array index out of bounds\n ");
	else
		stack[top] = value;
}

void pop()
{
	printf("pop\n");

	if(top != -1) {
		stack[top] = 0;
		top = top -1;
	} else {
		printf("stack empty\n");
	}	
}

void display(void)
{
	printf("stack values:\n");

	for (int i = top ; i >= 0; i--)
		printf("%d ", stack[i]);

	printf("\n\n");
}
 
 int main(void)
 {
	for (int i=0; i < MAX_ENTRIES; i++)
		push (i);
	
	display();
	pop();
	display();
	pop();
	display();
	pop();
	display();

	return 0;	
 }