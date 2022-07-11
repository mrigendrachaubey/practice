#include <stdio.h>

int front = -1, rear = -1;
int queue[5] = {0};


void enqueue(int value)
{
	queue[++front] = value; 
	if (rear == -1)
		rear++;
}

void dequeue(void)
{
	if (rear == -1)
		return;

	if(front == -1) {
		printf("queue is empty\n");
		rear = -1;
		return;
	}

	front--;
}

void showqueue(void)
{
	printf("front %d\n", front);
	for (int i = front ; i >= 0 ; i--)
		printf("%d ", queue[i]);
	printf("\n");
}

int main(void)
{
	enqueue(2);
	enqueue(4);
	enqueue(72);
	showqueue();
	dequeue();
	showqueue();
	dequeue();
	showqueue();
	dequeue();
	showqueue();
	dequeue();
	showqueue();
	dequeue();
	showqueue();
	return 0;
}