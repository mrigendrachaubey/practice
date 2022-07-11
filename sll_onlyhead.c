#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};

typedef struct node node;

node* create()
{
        node *p = malloc(sizeof(p));
        p->data = 1;
        p->next = NULL;
        return p;
}

void traverse(node *p)
{
       do {
                printf("%d\n", p->data);
       } while(p->next != NULL);
}

int main(void)
{
        node *p;
        p = create();
        traverse(p);
}
