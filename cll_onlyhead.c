#include <stdio.h>
#include <stdlib.h>

struct cll {
	int data;
	struct cll *next;
};

typedef struct cll node;

node *head=NULL;

void create(void)
{
	node *ptr = malloc(sizeof(node));
	ptr->data = 32;
	ptr->next = NULL;
	if (head == NULL)
		head = ptr;
}

int main(void)
{
	create();
	return 0;
}
