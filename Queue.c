#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int head = -1;
int tail = -1;

void enqueue(int value){
    if(tail == SIZE - 1){
        printf("\nQueue is full.");
        return;
    }

    if(head == -1){
        head++;
    }
    tail++;
    queue[tail] = value;
}

int dequeue(){
    if(head == -1 || head > tail){
        printf("\nQueue is empty.");
        return -1;
    }
    return queue[head++];
}

void printQueue(){
    if(head == -1 || head > tail){
        printf("\nQueue is empty.");
        return;
    }

    printf("\n");
    for (int i = head; i <= tail; i++)
    {
        printf("<=%d",queue[i]);
    }
}

int main(){
    dequeue();
    printQueue();
    enqueue(12);
    enqueue(21);
    enqueue(33);
    printQueue();
    dequeue();
    printQueue();
}