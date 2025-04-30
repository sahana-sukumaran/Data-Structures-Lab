//implementation of stackadt using singly linked list
#ifndef HEADER_H
#define HEADER_H
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
class stackadt
{
    struct node
    {
        char data;
        struct node* next;
    }*head;
    public:
    stackadt();
    bool empty();
    char push(char);
    void pop();
    char peek();
    void display();
};
bool stackadt::empty()
{
    if (head==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//function to push
char stackadt::push(char num)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("memory allocation failed\n");
        return 0;
    }
    newnode->data = num;
    newnode->next = head; 
    head = newnode; 
    return 1;
}


//function to pop
void stackadt::pop()
{
    if (head == NULL) 
    {
        return;
    }
    char data = head->data;
    head = head->next; 
    return;
}

//function to peek
char stackadt::peek()
{
    if (head == NULL) 
    {
        return '\0';
    }
    return head->data;
}
void stackadt::display()
{
    if (head==NULL)
    {
        printf("empty\n");
    }
    struct node* temp=head;
    while(temp!=NULL)
    {
        cout<<"   "<<temp->data;
        temp=temp->next;
    }
    printf("\n");
}
#endif
