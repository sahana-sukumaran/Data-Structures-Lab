//implementation of linked list using circular linked list

#include <stdio.h>
#include <stdlib.h>
class listadt
{
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head;
    public:
    listadt()
    {
        head=NULL;
    }
    void insert_beginning(int);
    void insert_end(int);
    void insert_position(int, int);
    int delete_beginning();
    int delete_end();
    int delete_position(int);
    int search(int);
    void display();
};


int main()
{
   int chc, data;
   listadt obj;
   while(1)
   {
       printf("\n1. Insert Beginning\n2. Insert End\n3. Insert Position");
       printf("\n4. Delete Beginning\n5. Delete End\n6. Delete Position");
       printf("\n7. Search\n8. Display\n9. Exit\n");
       printf("\nEnter your choice: ");
       scanf("%d",&chc);
       switch(chc)
       {
            case 1: 
                    printf("\nEnter the value to be inserted: ");
                    scanf("%d",&data);
                    obj.insert_beginning(data);
                    break;
            case 2: 
                    printf("\nEnter the value to be inserted: ");
                    scanf("%d",&data);
                    obj.insert_end(data);
                    break;
            case 3: 
                    printf("\nEnter the value to be inserted: ");
                    scanf("%d",&data);
                    printf("\nEnter the position: ");
                    int pos;
                    scanf("%d",&pos);
                    obj.insert_position(data, pos);
                    break;
            case 4: 
                    int del;
                    del = obj.delete_beginning();
                    break;
            case 5: 
                    int dele;
                    dele = obj.delete_end();
                    break;
            case 6: 
                    printf("enter the position: ");
                    int pos1;
                    scanf("%d", &pos1);
                    int delp;
                    delp = obj.delete_position(pos1);
                    break;
            case 7: 
                    printf("enter the element to be searched: ");
                    int ele;
                    scanf("%d", &ele);
                    int rtv;
                    rtv = obj.search(ele);
                    if(rtv==1)
                    {
                        printf("element was found\n");
                    }
                    else
                    {
                        printf("element was not found\n");
                    }
                    break;
            case 8: 
                    obj.display();
                    break;
            case 9:
                    exit(0);
                    break;
            default: 
                    printf("\nInvalid Choice\n");
       }
   }
   return 0;
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
    if (pos <= 0) 
    {
        return;
    }
    struct node* cur = head;
    if(pos == 1)
    {
        insert_beginning(data);
        return;
    }
    for (int i = 1; cur->next!=head&&i<pos-1;i++)
    {
        cur=cur->next;
    }
    
    if (cur->next == head) 
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
