/*
top node points to bottom nodes, last element is the top.
   top-----> node4
                |
             node3
                |
             node2
                |
             node1
                |
             NULL
*/


#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};

typedef struct node nde;

nde *top=NULL;

void push(int data)
{
       nde *s = malloc(sizeof(nde));
       s->data = data;

       if (top == NULL){
                s->next = NULL; /* first node's points to NULL*/
       }
       else {     
                s->next = top; /* new node points to previous top element*/
       }
       
       top = s; /* top points to latest node*/
}

void pop()
{
        if (top == NULL)
                printf("stack is empty\n");
        else {
                nde *tmp = top; /* point to top*/
                top = top->next;/* move top to point to bottom node*/
                free(tmp); /* free the node*/
        }        
}

void display()
{
        nde *tmp = top;
        while(tmp != NULL){
                printf("%d\n", tmp->data);
                tmp = tmp->next;
        }
        printf("\n");
}

int main(void)
{
        push(3);
        push(4);
        push(5);
        push(6);
        push(1);
        push(0);
        display();  
        pop();
        pop();
        display();
      
        return 0;

}
