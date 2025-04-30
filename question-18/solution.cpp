//implementation of queue adt using singly linked list
#include <cstdio>
#include <cstdlib>
class queueadt
{
    struct node
    {
        int data;
        struct node* next;
    }*head;
    public:
    queueadt()
    {
        head = NULL;
    }
    int enqueue(int);
    int dequeue();
    int peek();
};
int main()
{
    int chc;
    queueadt obj;
    do 
    {
        printf("enter: \n\t 1. for enqueue\n\t 2. for dequeue\n\t 3. for peeking\n\t 4. for exit\n");
        printf("enter the choice\n");
        scanf("%d", &chc);
        switch(chc)
        {
            case 1:
            {
                int num;
                printf("enter the number to be inserted\n");
                scanf(" %d", &num);
                int ret;
                ret=obj.enqueue(num);
                if (ret==1)
                {
                    printf("insertion was succesful\n");
                }
                else 
                {
                    printf("insertion was unsuccesful\n");
                }
                break;
            }
            case 2:
            {
                int ret;
                ret=obj.dequeue();
                if(ret=='\0')
                {
                    printf("queueadt underflows\n");
                }
                else
                {
                    printf("deletion was succesful. deleted value %d \n", ret);
                }
                break;
            }
            case 3:
            {
                printf("\ntop of queue is %d\n", obj.peek());
                break;
            }
            case 4:
            {
                return 0;
                break;
            }
            default:
            {
                printf("invalid input");
                break;
            }
        }
    }while(1);
}

//function to push
int queueadt::enqueue(int num)
{
    if(head==NULL)
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


//function to pop
int queueadt::dequeue()
{
    if (head == NULL) 
    {
        printf("queue underflow\n");
        return -9999;
    }
    int data = head->data;
    struct node* temp = head;
    head = head->next; 
    free(temp); 
    return data;
}

//function to peek
int queueadt::peek()
{
    if (head == NULL) 
    {
        printf("queue is empty\n");
        return -9999;
    }
    return head->data;
}


