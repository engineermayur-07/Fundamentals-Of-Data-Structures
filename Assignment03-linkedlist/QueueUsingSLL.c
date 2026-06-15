#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    struct node *next;
    int data;
};

struct node *rear = NULL;
struct node *front = NULL;
 

struct node *CreateNode(){
    struct node * newnode = malloc(sizeof(struct node));
    if( newnode == NULL){
        printf("\n Out of Memory ");
        return;
    }
    newnode->next = NULL;
    printf("\n Enter data to enqueue in the Queue :- ");
    scanf("%d" , &newnode->data);
    return newnode;
}


void display(){
    printf("--------Queue Using Linked List -----------\n");
    struct node *temp = front;
    if(rear == NULL){
        printf("\n No data to display, list is empty ");
        return;
    }
    printf("\tData :\n");
     
    while( temp != NULL ){
        printf("\tV\n");
        printf("\tdata : %d\n", temp->data);
        temp = temp->next;
    }

}

void enQueue(){
    struct node *newnode;
    newnode = CreateNode(); 

    if( newnode == NULL){
        return;
    }

    if(rear == NULL){

        rear = newnode ;
        front = rear ;
        printf("\n The element %d is enqueued successfully\n\n",rear->data);
        return ;

    }
    
    else{

        rear->next = newnode;
        rear = newnode;
        printf("\n The element %d is enqueued successfully\n\n",rear->data);
        return ;

    }
}

void deQueue(){

    struct node *temp;
    if(rear == front && front != NULL){
        printf("\n The element %d is dequeued successfully\n\n",front->data);
        temp = front;
        rear = NULL;
        front = NULL;
        free(temp);
        return ;
    }

    if( front == NULL ){
        printf("\n No element to dequeue\n\n");
        return ;
    }

    temp = front;
    printf("\n The element %d is dequeued successfully\n\n",front->data);
    front = front->next ;
    free(temp);
    return ;
    
}

int main(){
    int choice = -1;
    printf("-------- Queue Linked List -----------\n");

    while(1){
        printf("\tMENU\t\n");
        printf("\t1. Enqueue\t\n");
        printf("\t2. Dequeue\t\n");
        printf("\t3. Display\t\n");         
        printf("\t4. Exit\t\n");


        printf("\n Enter the choice no :- ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            enQueue();
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program ");
            return 0;
        default :
            printf("Invalid Choice");
        }
    }
    return 0;
}