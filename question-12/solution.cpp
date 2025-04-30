//implementation of stack using character array
#include <cstdio>

class stackadt
{
    int top;
    char list[5];
    public:
    stackadt()
    {
        top=-1;
        for(int i = 0; i<5; i++)
        {
            list[i]='\0';
        }
    }
    int push(char);
    char pop();
    void peek();
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
                printf("enter the character to be inserted\n");
                scanf(" %c", &num);
                int ret;
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
                obj.peek();
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

int stackadt::push(char num)
{
    if (top==4)
    {
        printf("stackadt overflows\n");
        return 0;
    }
    top++;
    list[top]=num;
    return 1;
}

char stackadt::pop()
{
    if(top==-1)
    {
        return '\0';
    }
    char data = list[top];
    if(top==0)
    {
        top=-1;
        list[0]='\0';
        return data;
    }
    top--;
    return data;
}

void stackadt::peek()
{
    printf("%c\n", list[top]);
}
