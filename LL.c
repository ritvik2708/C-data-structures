#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node{
    int data;
    struct node* next;
};

struct node* head=NULL;
struct node* tail=NULL;

void insertFirst(int data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node*));//malloc creates an object of the required size and returns its location as a pointer.
    new_node->data=data;
    new_node->next=head;
    if(head==NULL){
        tail=new_node;
    }
    head=new_node;
}

void insertLast(int data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node*));
    new_node->data=data;
    new_node->next=NULL;
    tail->next=new_node;
    tail=new_node;
    if(head==NULL){
        head=new_node;
    }
}

void deleteFirst(){
    if(head==NULL){
        printf("\nThe list is already empty");
        return;
    }
    struct node* temp;
    temp=head;
    head=head->next;
    if(head==NULL){
        tail=NULL;
    }
    free(temp);
}

void deleteLast(){
    if(head==NULL){
        printf("\nThe list is already empty");
    }
    struct node* ptr;
    struct node* temp;
    ptr=head;
    while(ptr!=NULL){
        if(ptr->next==NULL&&ptr==head){
            free(head);
            head=NULL;
            free(tail);
            tail=NULL;
            break;
        }
        if(ptr->next->next==NULL){
            temp=ptr->next;
            ptr->next=NULL;
            tail=ptr;
            free(temp);
            break;
        }
        ptr=ptr->next;
    }
}

void update(int val,int data){
    if(head==NULL){
        printf("\nList is currently empty");
    }
    struct node* temp;
    temp=head;
    while(temp!=NULL){
        if(temp->data==val){
            temp->data=data;
            break;
        }
        temp=temp->next;
    }
}

void display(){
    if(head==NULL){
        printf("\nNothing to be displayed\n");
        return;
    }
    struct node* ptr=head;
    while(ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }
    printf("END\n");
}

int main()
{
    display();
    insertFirst(5);
    display();
    insertLast(10);
    display();
    update(10,20);
    display();
    deleteFirst();
    display();
    insertFirst(40);
    display();
    deleteLast();
    display();
    insertFirst(50);
    display();
    insertLast(60);
    display();
}
