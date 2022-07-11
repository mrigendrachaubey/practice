#include <stdio.h>
#include <stdlib.h>

struct blob{
	int data;
	struct blob *next;
};

typedef struct blob node;
node *head = NULL;


void create() {
	node *p = malloc(sizeof(p));
	node *tmp;

	p->data = 34;
	p->next = NULL;

	if (head == NULL) {
		head = p;
	} else {
		tmp = head;
		while(tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = p;
	}
}

void traverse()
{
	node *tmp = head;
	while(tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

void add(int location, int value)
{
	node *p = malloc(sizeof(p));
	int i;
	p->data = value;
	p->next = NULL;

	node *tmp = head, *ptr;

	for (i = 1; i < location-1; i++)
		tmp = tmp->next;

	ptr = tmp->next;
	tmp->next=p;
	p->next = ptr;
}

void delete(int location) {
	node *tmp = head, *ptr;
	int i;
	for (i = 1; i < location-1; i++)
		tmp = tmp->next;

	ptr = tmp->next;
	tmp->next = tmp->next->next;
	free(ptr);
}

int main(void)
{
	int i;
	for (i=0; i < 10; i++)
		create();
	printf("##\n");
	traverse();	
	add(7,64);
	printf("##\n");
	traverse();
	delete(7);
	printf("##\n");
	traverse();
	return 0;
}

