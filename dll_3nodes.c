#include <stdio.h>
#include <stdlib.h>
#define num_nodes 3
struct dll  {
		struct dll *prev;
		int data;
		struct dll *next;
};

typedef struct dll node;

node *head = NULL;

void create(){
	node *node, *tmp;
	node = malloc(sizeof(node));

	node->next = NULL;
	node->prev = NULL;
	node->data = 21;
	
	if (head == NULL) {
		head = node;
s	}else{
		tmp = head;
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
		node->prev = tmp;
		node->next = NULL;
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

int main(void) {
	int i;
	for (i=0; i < num_nodes; i++)
		create();
	traverse();
	return 0;
}