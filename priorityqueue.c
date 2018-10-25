// Created by Ritvik on 05-10-2018.
#include <stdio.h>
#include <stdlib.h>

typedef struct priQue{
    int* arr;
    int size;
    int rear;
}queue;

void create(queue* prique){
    prique->arr=(int*)malloc(prique->size* sizeof(int));
    prique->rear=-1;
}

void add(queue* prique,int data){
    if(prique->rear==prique->size-1){
        printf("The queue is full\n");
        return;
    }
    int parentnode=0;
    int current=++prique->rear;
    while(current>0){
        parentnode=(current-1)/2;
        if(prique->arr[parentnode]>=data){
            prique->arr[current]=data;
            return;
        }
        prique->arr[current]=prique->arr[parentnode];
        current=parentnode;
    }
    prique->arr[0]=data;
}

void swap(queue* prique,int l1,int l2){
    int temp=prique->arr[l1];
    prique->arr[l1]=prique->arr[l2];
    prique->arr[l2]=temp;
}

void delete(queue* prique){
    if(prique->rear==-1){
        printf("The queue is already empty\n");
        return;
    }
    printf("The deleted element is %d\n",prique->arr[0]);
    swap(prique,0,prique->rear);
    prique->rear--;
    int current=0;
    while(current<prique->rear){
        int greater=current;
        int lChild=2*current+1;
        int rChild=2*current+2;
        if(lChild<=prique->rear&&prique->arr[current]<prique->arr[lChild]){
            greater=lChild;
        }
        if(rChild<=prique->rear&&prique->arr[current]<prique->arr[rChild]){
            greater=rChild;
        }
        if(greater==current){
            return;
        }
        swap(prique,current,greater);
    }
}

void display(queue* prique){
    if(prique->rear==-1){
        printf("The queue is empty\n");
        return;
    }
    int i;
    for(i=0;i<=prique->rear;i++){
        printf("%d ",prique->arr[i]);
    }
}

int main(){
    int size;
    queue prique1;
//    scanf("%d",&size);
    prique1.size=10;
    create(&prique1);
    add(&prique1,4);
    add(&prique1,80);
    add(&prique1,12);
    add(&prique1,16);
    add(&prique1,100);
//    delete(&prique1);
    display(&prique1);
}

