/*

update rear to new node

        node1 -> node2 -> node3 -> node4
        |                           |
       front                       rear                            
*/


#include <stdio.h>
#include <stdlib.h>

struct queue{
        int data;
        struct queue *back;
};

typedef struct queue node;

node *front = NULL;
node *rear = NULL;


void enqueue(int data)
{
        node *s = malloc(sizeof(node));
        s->data = data;
        s->back = NULL;

        if((front == NULL) && (rear == NULL)){
                rear = front = s;/* front points to first node*/

        }else
                rear->back = s;/* previous node points to new node*/

        rear = s;/* rear points to new node*/
}

void dequeue()
{
        if(front == NULL){
                printf("queue cleared\n");
                rear = NULL;
        }else{
                node *tmp = front;
                front = tmp->back;
                free(tmp);
        }
}

void display(void)
{
        node *tmp = front;
        if((front == NULL) && (rear == NULL)){
                printf("queue is empty");
        }                
        while(tmp != NULL){
                printf("%d ", tmp->data);
                tmp = tmp->back;
        }
        printf("\n");
}

int main(void)
{
        enqueue(5);
        enqueue(4);
        enqueue(3);
        enqueue(45);
        enqueue(41);
        enqueue(47);
        display();
        dequeue();
        display();
        dequeue();
        dequeue();
        dequeue();  
        display();     
        dequeue();
        dequeue();
        dequeue();  
        display();                           
        return 0;
}
