#include <stdio.h>
#include <stdlib.h>

struct Node{
    int Data;
    struct Node* Next;
};

struct Node* Head = NULL;

void AddFirst(int value){
    struct Node* newNode = NULL;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->Data = value;
    newNode->Next = NULL;

    if(Head == NULL){
        Head = newNode;
        return;
    }

    newNode->Next = Head;
    Head = newNode;
}

void AddLast(int value){
    struct Node* newNode = NULL;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->Data = value;
    newNode->Next = NULL;

    if(Head == NULL){
        Head = newNode;
        return;
    }

    struct Node* temp = NULL;
    temp = Head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void AddAfter(int nth, int value){
    int len = LengthOfList();
    int count = 1;

    if(nth > len || nth < 1){
        printf("\nOverflow.");
        return;
    }

    struct Node* newNode = NULL;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->Data = value;
    newNode->Next = NULL;

    struct Node* temp = NULL;
    temp = Head;

    while (count < nth)
    {
        temp = temp->Next;
        count++;
    }
    newNode->Next = temp->Next;
    temp->Next = newNode;
}

void AddBefore(int nth, int value){
    int len = LengthOfList();
    int count = 2;

    if(nth > len || nth < 1){
        printf("\nOverflow.");
        return;
    }

    struct Node* newNode = NULL;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->Data = value;
    newNode->Next = NULL;

    if(nth == 1){
        AddFirst(value);
        return;
    }
    
    struct Node* temp = NULL;
    temp = Head;

    while (count < nth)
    {
        temp = temp->Next;
        count++;
    }
    newNode->Next = temp->Next;
    temp->Next = newNode;
}

void PrintLinkedList(){
    if(Head == NULL){
        printf("\nEmpty list.");
        return;
    }
    struct Node* temp = NULL;
    temp = Head;
    printf("\n");
    while (temp != NULL)
    {
        printf(" %d =>",temp->Data);
        temp =temp->Next;
    }
    
}

int LengthOfList(){
    int count = 0;
    if(Head == NULL){
        return count;
    }
    struct Node* temp = NULL;
    temp = Head;
    while (temp != NULL)
    {
        temp = temp->Next;
        count++;
    }

    return count;    
}

int main(){
    PrintLinkedList();
    AddLast(10);
    AddLast(20);
    AddLast(30);
    PrintLinkedList();
    AddFirst(40);
    PrintLinkedList();
    AddAfter(2,50);
    PrintLinkedList();
    AddBefore(5,60);
    PrintLinkedList();
    AddAfter(6,70);
    PrintLinkedList();
    AddBefore(1,80);
    PrintLinkedList();
    printf("\n%d",LengthOfList());
}