#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* l;
    struct Node* r;
}node;

node* root=NULL;

node* create(int data){
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->l=NULL;
    temp->r=NULL;
    return temp;
}

void insert(int data){
    if(root==NULL){
        root=create(data);
        return;
    }
    node* temp=root;
    while(temp!=NULL){
        if(data>=temp->data){
            if(temp->r==NULL){
                temp->r=create(data);
                return;
            }
            temp=temp->r;
        }
        else{
            if(temp->l==NULL){
                temp->l=create(data);
                return;
            }
            temp=temp->l;
        }
    }
}

node* searchNode(int data,int flag){
    node* temp=root;
    while(temp!=NULL){
        if(temp->data==data){
            if(!flag) {
                printf("The given element exists\n");
            }
            return temp;
        }
        else if(data>temp->data){
            temp=temp->r;
        }
        else{
            temp=temp->l;
        }
    }
    if(!flag) {
        printf("The given element does not exist\n");
    }
    return NULL;
}

void search(int data){
    searchNode(data,0);
}

void bothChild(node *nodeDelete){
    if(nodeDelete->r->l==NULL){
        printf("The deleted element is %d\n",nodeDelete->data);
        nodeDelete->data=nodeDelete->r->data;
        nodeDelete->r=nodeDelete->r->r;
        return;
    }
    node* temp=nodeDelete->r;
    while(temp->l!=NULL){
        if(temp->l->l==NULL){
            printf("The deleted element is %d\n",nodeDelete->data);
            nodeDelete->data=temp->l->data;
            temp->l=temp->l->r;
            return;
        }
        temp=temp->l;
    }
}

void delete(int data){
    if(root==NULL){
        printf("The tree has no elements\n");
        return;
    }
    if(root->data==data){
        if(root->l==NULL&&root->r==NULL){
            printf("The deleted element is : %d\n",root->data);
            root=NULL;
        }
        else if(root->l!=NULL&&root->r!=NULL){
            bothChild(root);
        }
        else{
            root=root->l==NULL?root->r:root->l;
        }
    }
    node* current=root;
    node* nodeDelete=searchNode(data,1);
    if(nodeDelete==NULL) {
        printf("The given data is not available in the tree\n");
        return;
    }
    else if(nodeDelete->l!=NULL&&nodeDelete->r!=NULL) {
        bothChild(nodeDelete);
    }
    else{
        while(1){
            if(current->data>data){
                if(current->l->data==data){
                    printf("The deleted element is %d\n",current->l->data);
                    if(current->l->l==NULL&&current->l->r==NULL){
                        current->l=NULL;
                    }
                    else{
                        current->l=current->l->l==NULL?current->l->r:current->l->l;
                    }
                    break;
                }
                else{
                    current=current->l;
                }
            }
            else{
                if(current->r->data==data){
                    printf("The deleted element is %d\n",current->r->data);
                    if(current->r->l==NULL&&current->r->r==NULL){
                        current->r=NULL;
                    }
                    else{
                        current->r=current->r->l==NULL?current->r->r:current->r->l;
                    }
                    break;
                }
                else{
                    current=current->r;
                }
            }
        }
    }
}
void displayPre(node* temp){
    if(temp==NULL){
        return;
    }
    printf("%d ",temp->data);
    displayPre(temp->l);
    displayPre(temp->r);
}

void display(){
    if(root==NULL){
        printf("The tree has no elements\n");
        return;
    }
    printf("Pre Order: ");
    displayPre(root);
    printf("\n");
}

int main() {
    insert(10);
    display();
    insert(8);
    display();
    insert(12);
    display();
    insert(16);
    display();
    insert(20);
    display();
    insert(4);
    display();
    insert(2);
    display();
    insert(6);
    display();
    search(17);
    search(20);
    insert(9);
    display();
    delete(4);
    display();
}