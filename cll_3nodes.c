#include <stdio.h>
#include <stdlib.h>

struct cll {
	int data;
	struct cll *next;
};

typedef struct cll node;

node *head = NULL;

void create(void)
{
	node *tmp, ptr = malloc(sizeof(node));
	ptr->data = 32;
	ptr->next = NULL;

	tmp = head;
	if(head == NULL) {
		head = ptr;
	} else {
		while (tmp->next != NULL)
			tmp = tmp->next;
	}
		
}

int main(void)
{
	create();
	traverse();
}