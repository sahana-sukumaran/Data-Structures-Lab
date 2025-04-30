//program to implements list adt using a singly linked list

#include <cstdio>
#include <cstdlib>

class listadt
{
    struct node
    {
        int data;
        struct node* next;
    }*head;
    public:
    listadt()
    {
        head=NULL;
    }
    int insert_beginning(int);
    int insert_end(int);
    int insert_position(int, int);
    int delete_beginning();
    int delete_end();
    int delete_position(int);
    void display();
    void reverse_display();
    int reverse_link();
    int search(int);
};

int main()
{
    int chc;
    listadt obj;
    do 
    {
        printf("enter: \n\t 1. for inserting at the beginning\n\t 2. for inserting at the end\n\t 3. for inserting at a position\n\t 4. for deleting at the beginning\n\t 5. for deleting at the end\n\t 6. for deleting at a position\n\t 7. for searching\n\t 8. for displaying\n\t 9. for reverse display\n\t 10. for reverse link\n\t 11. for exit\n");
        printf("enter the choice\n");
        scanf("%d", &chc);
        switch(chc)
        {
            case 1:
            {
                int num;
                printf("enter the number to be inserted\n");
                scanf("%d", &num);
                int ret;
                ret=obj.insert_beginning(num);
                if (ret==1)
                {
                    printf("insertion was successful\n");
                }
                else 
                {
                    printf("insertion was unsuccessful\n");
                }
                break;
            }
            case 2:
            {
                int num;
                printf("enter the number to be inserted\n");
                scanf("%d", &num);
                int ret;
                ret=obj.insert_end(num);
                if (ret==1)
                {
                    printf("insertion was successful\n");
                }
                else 
                {
                    printf("insertion was unsuccessful\n");
                }
                break;
            }
            case 3:
            {
                int num;
                printf("enter the number to be inserted\n");
                scanf("%d", &num);
                int ret;
                int pos;
                printf("enter the position. 1 is the first position\n");
                scanf("%d", &pos);
                ret=obj.insert_position(num, pos);
                if (ret==1)
                {
                    printf("insertion was successful\n");
                }
                else 
                {
                    printf("insertion was unsuccessful\n");
                }
                break;
            }
            case 4:
            {
                int ret;
                ret=obj.delete_beginning();
                if(ret==-9999)
                {
                    printf("deletion was unsuccessful\n");
                }
                else
                {
                    printf("deletion was successful. deleted value %d \n", ret);
                }
                break;
            }
            case 5:
            {
                int ret;
                ret=obj.delete_end();
                if(ret==-9999)
                {
                    printf("deletion was unseccessful\n");
                }
                else
                {
                    printf("deletion was successful. deleted value %d \n", ret);
                }
                break;
            }
            case 6:
            {
                int ret;
                int pos;
                printf("enter the position. 1 is the first position\n");
                scanf("%d", &pos);
                ret=obj.delete_position(pos);
                if(ret==-9999)
                {
                    printf("deletion was unseuccessful\n");
                }
                else
                {
                    printf("deletion was successful. deleted value %d \n", ret);
                }
                break;
            }
            case 7:
            {
                int key;
                printf("enter the number to be searched\n");
                scanf("%d", &key);
                int ret;
                ret=obj.search(key);
                if (ret>0)
                {
                    printf("the element was found at position %d \n", ret);
                }
                else 
                {
                    printf("the element was not found\n");
                }
                break;
            }
            case 8:
            {
                obj.display();
                break;
            }
            case 9:
            {
                obj.reverse_display();
                break;
            }
            case 10:
            {
                int ret=obj.reverse_link();
                if (ret==1)
                {
                    printf("reversal was successful\n");
                }
                else
                {
                    printf("reversal was unsuccessful\n");
                }
                break;
            }
            case 11:
            {
                return 0;
                break;
            }
            default:
            {
                printf("invalid input\n");
                break;
            }
        }
    }while(chc<11);
}

//function to insert at the beginning
int listadt::insert_beginning(int num)
{
    struct node* newnode=(struct node*)(malloc(sizeof(struct node)));
    if (newnode==NULL)
    {
        printf("memory allocation failed\n");
        return 0;
    }
    newnode->data=num;
    newnode->next=head;
    head=newnode;
    return 1;
}


//function to insert at the end
int listadt::insert_end(int num)
{
    if(head==NULL)
    {
        return insert_beginning(num);
    }
    struct node* newnode=(struct node*)(malloc(sizeof(struct node)));
    if (newnode==NULL)
    {
        printf("memory allocation failed\n");
        return 0;
    }
    struct node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    newnode->data=num;
    newnode->next=NULL;
    temp->next=newnode;
    return 1;
}



//function to insert at a position
int listadt::insert_position(int num, int pos)
{
    if (pos==0)
    {
        printf("invalid position\n");
        return 0;
    }
    if(pos==1)
    {
        return insert_beginning(num);
    }
    struct node* newnode=(struct node*)(malloc(sizeof(struct node)));
    if (newnode==NULL)
    {
        printf("memory allocation failed\n");
        return 0;
    }
    newnode->data=num;
    struct node* temp=head;
    for (int i = 1; temp!=NULL&&i<pos-1;i++)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("invaid position\n");
        return 0;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return 1;
}


//function to delete at the beginning
int listadt::delete_beginning()
{
    if(head==NULL)
    {
        printf("list is empty\n");
        return -9999;
    }
    int data=head->data;
    if(head->next==NULL)
    {
        head=NULL;
        return data;
    }
    head=head->next;
    return data;
}


//function to delete at the end
int listadt::delete_end()
{
    if(head==NULL)
    {
        printf("list is empty\n");
        return -9999;
    }
    if(head->next==NULL)
    {
        return delete_beginning();
    }
    struct node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    int data=temp->next->data;
    temp->next=NULL;
    return data;
}


//function to delete at a position
int listadt::delete_position(int pos)
{
    if(head==NULL)
    {
        printf("list is empty\n");
        return -999;
    }
    int data;
    if(pos==1)
    {
        return delete_beginning();
    }
    struct node* temp=head;
    for (int i = 1; temp!=NULL&&i<pos-1;i++)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("invaid position\n");
        return 0;
    }
    data=temp->next->data;
    temp->next=temp->next->next;
    return data;
}


//function to search for an element
int listadt::search(int key)
{
    if(head==NULL)
    {
        return -1;
    }
    struct node* temp=head;
    int pos=0;
    while(temp!=NULL)
    {
        pos++;
        if(temp->data==key)
        {
            return pos;
        }
        else
        {
            temp=temp->next;
        }
    }
    return 0;
}


//function to display
void listadt::display()
{
    if (head==NULL)
    {
        printf("list is empty");
    }
    else
    {
        struct node*temp=head;
        while(temp!=NULL)
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
    }
    printf("NULL\n");
}

int listadt::reverse_link()
{
    if(head==NULL)
    {
        printf("list is empty\n");
        return 0;
    }
    struct node* prev = NULL;
    struct node* cur = head;
    struct node* next1 = NULL;
    while(cur!=NULL)
    {
        next1=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next1;
    }
    head=prev;
    return 1;
}

void listadt::reverse_display()
{
    int ret=reverse_link();
    display();
    int rev1=reverse_link();
}
