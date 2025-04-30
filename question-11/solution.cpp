//implementing round robin scheduling 

#include "circular_linked_list_header.h"

void insert(int, listadt&);
void execute(int, listadt&);
listadt::listadt()
{
    head=NULL;
}
int main()
{
    int chc;
    listadt obj;
    int slt=0;
    printf("enter the time slot\n");
    scanf("%d", &slt);
    do {
        printf("enter: \n\t 1. for inserting\n\t 2. for executing \n\t 3. for exit\n");
        printf("enter the choice\n");
        scanf("%d", &chc);

        switch (chc) 
        {
            case 1: 
            {
                int num;
                printf("enter the number to be inserted\n");
                scanf("%d", &num);
                insert(num, obj);
                break;
            }
            case 2: 
            {
                execute(slt, obj);
                break;
            }
            case 3:
                exit(0);
                break;
            default:
                printf("invalid input\n");
                break;
        }
    } while (chc !=5);
}

void insert(int num, listadt& obj)
{
    obj.listadt::insert_end(num);
    obj.listadt::display();
}

void execute(int slt, listadt& obj)
{
    int x=obj.listadt::gethead();
    if (x!=0)
    {
        int ret = obj.listadt::delete_beginning();
        ret=ret-slt;
        if (ret<=0)
        {
            printf("operation was successful\n");
        }
        else
        {
            obj.listadt::insert_end(ret);
            printf("operation was successful\n");
        }
    }
    else
    {
        printf("the queue is empty\n");
        return;
    }    
}
