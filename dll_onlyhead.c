#include <stdio.h>
#include <stdlib.h>

struct dll {
		struct dll *prev;
		int data;
		struct dll *next;
};

struct dll *head;

void create() {
	head = malloc(sizeof(head));
	head->prev = head->next = NULL;
	head->data = 34;
}

void traverse(void) {
	printf("%d\n", head->data);
}
int main(void) {
	create();
	traverse();
	return 0;
}