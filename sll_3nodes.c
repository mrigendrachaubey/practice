#include <stdio.h>
#include <stdlib.h>

struct list {
        int data;
        struct list *next;
};

typedef struct list list;

list *head = NULL;

list * create(void)
{
	list *p = malloc(sizeof(p));
	p->data = 23;
	
	list *tmp;	
	tmp = head;

	if (head == NULL){
		p->next = NULL;
	} else {
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = p;
		p->next = NULL;
	}

	return p;
}

void traverse(list *p)
{
	list *tmp = p;
	while(tmp != NULL)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}
int main(void)
{
	list *p;
	int list_size=0;
	head = create();
	for (list_size = 3; list_size != 1; list_size--){
		create();
	}
	traverse(head);
	return 0;
}
        
