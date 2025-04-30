#ifndef HEADER_H
#define HEADER_H
#include <cstdio>
#include <cstdlib>
class listadt
{
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head;
    public:
    listadt();
    int gethead();
    void insert_beginning(int);
    void insert_end(int);
    void insert_position(int, int);
    int delete_beginning();
    int delete_end();
    int delete_position(int);
    int search(int);
    void display();
};
int listadt::gethead()
{
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void listadt:: insert_beginning(int data)
{
    struct node *new_node=(struct node*)(malloc(sizeof(struct node)));
    if (head == NULL)
    {
        new_node->data=data;
        new_node->next = new_node;
        head = new_node;
    }
    else
    {
        new_node->data=data;
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        new_node->next = head;
        temp->next = new_node; 
        head = new_node;
    }
}
void listadt::insert_end(int data)
{
    struct node *new_node=(struct node*)(malloc(sizeof(struct node)));
    if(head == NULL)
    {
        insert_beginning(data);
        return;
    }
    struct node* cur = head;
    while(cur->next!=head)
    {
        cur=cur->next;
    }
    cur->next=new_node;
    new_node->data=data;
    new_node->next=head;
}
void listadt::insert_position(int data, int pos) 
{
    struct node* new_node = (struct node*)(malloc(sizeof(struct node)));
    new_node->data = data;
    if (pos == 0) 
    {
        return;
    }
    struct node* cur = head->next;
    if(pos == 1)
    {
        insert_beginning(data);
        return;
    }
    for (int i = 1; cur!=head&&i<pos-1;i++)
    {
        cur=cur->next;
    }
    
    if (cur == head) 
    {
        printf("Invalid position\n");
        return; 
    }
    new_node->next = cur->next; 
    cur->next = new_node;        
}
int listadt::delete_beginning()
{
    if(head==NULL)
    {
        printf("list is empty\n");
        return -99999;
    }
    if (head->next==head)
    {
        int ret = head->data;
        head=NULL;
        return ret;
    }
    int data = head->data;
    struct node* temp=head->next;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    head = head->next;
    temp->next=head;
    return data;
}
int listadt::delete_end()
{
    if(head==NULL)
    {
        printf("list is empty\n");
        return -99999;
    }
    struct node* cur = head;
    if(cur->next==head)
    {
        head=NULL;
        return cur->data;
    }
    while(cur->next->next!=head)
    {
        cur=cur->next;
    }
    int temp = cur->data;
    cur->next=head;
    return temp;
}
int listadt::delete_position(int pos)
{
    if (head == NULL) 
    {
        printf("List is empty\n");
        return -99999;
    }

    if (pos == 1) 
    {
        int rtv = delete_beginning();
        return rtv;
    }

    struct node* cur = head;

    for (int i = 1; cur != NULL && i < pos - 1; i++) 
    {
        cur = cur->next;
    }

    if (cur == NULL || cur->next == NULL) 
    {
        printf("Invalid position\n");
        return -99999;
    }

    struct node* to_free = cur->next;  
    int data = to_free->data;         
    cur->next = to_free->next;        
    free(to_free);                    

    return data;
}

int listadt::search(int ele)
{
    if(head == NULL)
    {
        printf("\nList is empty\n");
        return 0;
    }
    struct node *temp=head;
    do
    {
        if(temp->data==ele)
        {
            return 1;
        }
        temp = temp->next;
    }while(temp != head);
    return 0;
}
void listadt::display()
{
    if(head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    struct node *temp=head;
    do
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }while(temp != head);
    printf("end of list\n");
}

#endif
