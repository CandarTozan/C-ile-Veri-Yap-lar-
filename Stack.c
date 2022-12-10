#include<stdio.h>

#define SIZE 5

int stack[SIZE];
int top = -1;

int isEmpty(){
    if(top == -1)
        return 1;
    return 0;
}

int isFull(){
    if(top == SIZE - 1)
        return 1;
    return 0;
}

void push(int value){
    if(isFull()){
        printf("\nStack is full");
        return;
    }
    stack[++top] = value;
}

int peek(){
    if(isEmpty()){
        printf("\nEmpty stack.");
        return -1;
    }
    return stack[top];
}

int pop(){
    if(isEmpty()){
        printf("\nEmpty stack.");
        return -1;
    }
    int temp = stack[top];
    top--;
    return temp;
}

void printStack(){
    if(isEmpty()){
        printf("\nEmpty stack.");
        return;
    }

    printf("\n");
    for (int i = 0; i <= top; i++)
    {
        printf("%d=>",stack[i]);
    }
    
}

int main(){
    push(12);
    push(21);
    push(33);
    printStack();
    pop();
    printStack();
    printf("\n%d",peek());
}