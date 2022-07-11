#include <stdio.h>
#include <stdlib.h>

#define num_nodes 5

struct dll {
		struct dll *prev;
		int data;
		struct dll *next;
};

typedef struct dll node;

node *head = NULL;

void create()
{
	node *ptr, *tmp = NULL;
	ptr = malloc(sizeof(node));
	ptr->data = 45;
	ptr->next = NULL;
	ptr->prev = NULL;
	if (head == NULL) {
		head = ptr;
	}else {
		tmp = head;
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ptr;
		ptr->prev = tmp;
		ptr->next = NULL;
	}
}

void traverse(void) 
{
	node *tmp = head;
	while(tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

void add(int location)
{
	int i;
	node *tmp = head;
	
	node *ptr = malloc (sizeof(node));
	ptr->data = 66;
	ptr->prev = NULL;
	ptr->next = NULL;

	for (i=1; i <location -1; i++)
	{
		tmp = tmp->next;
	}

	tmp->next->prev = ptr;
	ptr->next = tmp->next;
	ptr->prev = tmp;
	tmp->next = ptr;	
}

void delete(int location)
{
	int i;
	node *ptr, *lose, *tmp = head;
	for(i=1; i < location -1; i++)
			tmp = tmp->next;

	lose = tmp->next;
	ptr = tmp->next;
	tmp->next = ptr->next;
	ptr->next->prev = tmp;
	free(lose);	
}

int main(void)
{
	int i;
	for (i = 0; i < num_nodes; i++)
		create();
	traverse();
	add(3);
	traverse();
	delete(3);
	traverse();
	return 0;
}