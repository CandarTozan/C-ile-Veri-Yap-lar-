#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

int isFull(){
    if((front == 0 && rear == SIZE - 1) || front == rear + 1){
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(front == -1){
        return 1;
    }
    return 0;
}

void enQueue(int value){
    if(isFull()){
        printf("\nQueue is full.");
        return;
    }

    if(front == -1){
        front++;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
}

int deQueue(){
    if(isEmpty()){
        printf("\nEmpty queue.");
        return -1;
    }
    
    int temp = queue[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front = (front +1) % SIZE;
    }
    return temp;
}

void PrintQueue(){
    if(isEmpty()){
        printf("\nEmpty queue.");
        return;
    }
    int i;
    printf("\n");
    
    for(i = front; i != rear; i = (i + 1) % SIZE){
        printf("<=%d",queue[i]);
    }
    printf("<=%d",queue[i]);
}

int main(){
    deQueue();
    PrintQueue();
    enQueue(10);
    enQueue(20);
    enQueue(30);
    enQueue(40);
    enQueue(50);
    enQueue(60);
    PrintQueue();
    deQueue();
    PrintQueue();

    return 0;
}