//implementation of stackadt using singly linked list
#include <cstdio>
#include <cstdlib>
class stackadt
{
    struct node
    {
        char data;
        struct node* next;
    }*head;
    public:
    stackadt()
    {
        head = NULL;
    }
    int push(char);
    char pop();
    char peek();
};
int main()
{
    int chc;
    stackadt obj;
    do 
    {
        printf("enter: \n\t 1. for pushing\n\t 2. for popping\n\t 3. for peeking\n\t 4. for exit\n");
        printf("enter the choice\n");
        scanf("%d", &chc);
        switch(chc)
        {
            case 1:
            {
                char num;
                printf("enter the number to be inserted\n");
                scanf(" %c", &num);
                char ret;
                ret=obj.push(num);
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
                char ret;
                ret=obj.pop();
                if(ret=='\0')
                {
                    printf("stackadt underflows\n");
                }
                else
                {
                    printf("deletion was succesful. deleted value %c \n", ret);
                }
                break;
            }
            case 3:
            {
                printf("\ntop of stack is %c\n", obj.peek());
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
int stackadt::push(char num)
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
char stackadt::pop()
{
    if (head == NULL) 
    {
        printf("stack underflow\n");
        return '\0';
    }
    char data = head->data;
    struct node* temp = head;
    head = head->next; 
    free(temp); 
    return data;
}

//function to peek
char stackadt::peek()
{
    if (head == NULL) 
    {
        printf("Stack is empty\n");
        return '\0';
    }
    return head->data;
}
