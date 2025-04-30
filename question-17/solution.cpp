//implementation of queue using int array
#include <cstdio>

class queueadt
{
    int front;
    int rear;
    int que[5];
    public:
    queueadt()
    {
        front=-1;
        rear=-1;
        for(int i = 0; i<5; i++)
        {
            que[i]=0;
        }
    }
    void push(int);
    int pop();
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
                printf("enter the character to be inserted\n");
                scanf("%d", &num);
                obj.push(num);
                break;
            }
            case 2:
            {
                int ret;
                ret=obj.pop();
                if(ret==-99999)
                {
                    printf("queue underflows\n");
                }
                else
                {
                    printf("deletion was succesful. deleted value %d \n", ret);
                }
                break;
            }
            case 3:
            {
                int ret=obj.peek();
                if (ret==-99999)
                {
                    printf("the queue is empty\n");
                }
                else
                {
                    printf("%d\n", ret);
                }
                break;
            }
            case 4:
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
    }while(1);
}

void queueadt::push(int num)
{
    if (front==-1&&rear==-1)
    {
        front=0;
        rear=0;
        que[rear]=num;
    }
    else if((rear + 1) % 5 == front)
    {
        printf("queue is full\n");
    }
    else
    {
        rear = (rear + 1) % 5;
        que[rear]=num;
    }
}

int queueadt::pop()
{
    if(front==-1)
    {
        printf("queue is empty\n");
        return -99999;
    }
    else if(front==rear)
    {
        int data=que[front];
        front=-1;
        rear=-1;
        return data;
    }
    else
    {
        int data=que[front];
        front = (front + 1) % 5;
        return data;
    }
}

int queueadt::peek()
{
    if (front==-1)
    {
        return -99999;
    }
    else
    {
        return que[front];
    }
}
