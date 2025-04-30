//implementation of list adt

#include <cstdio>

class listadt
{
    int cur;
    int list[5];
    public:
    listadt()
    {
        cur=-1;
        for(int i = 0; i<5; i++)
        {
            list[i]=0;
        }
    }
    int insert_beginning(int);
    int insert_end(int);
    int insert_position(int, int);
    int delete_beginning();
    int delete_end();
    int delete_position(int);
    void display();
    int rotate(int);
    int search(int);
};

int main()
{
    int chc;
    listadt obj;
    do 
    {
        printf("enter: \n\t 1. for inserting at the beginning\n\t 2. for inserting at the beginning\n\t 3. for inserting at a position\n\t 4. for deleting at the beginning\n\t 5. for deleting at the end\n\t 6. for deleting at a position\n\t 7. for searching\n\t 8. for displaying\n\t 9. for rotating\n\t 10. for exit\n");
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
                int num;
                printf("enter the number to be inserted\n");
                scanf("%d", &num);
                int ret;
                ret=obj.insert_end(num);
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
            case 3:
            {
                int num;
                printf("enter the number to be inserted\n");
                scanf("%d", &num);
                int ret;
                int pos;
                printf("enter the position. 0 is the first position\n");
                scanf("%d", &pos);
                
                if (pos>5||pos<0)
                {
                    printf("invalid position was entered\n");
                }
                ret=obj.insert_position(num, pos);
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
            case 4:
            {
                int ret;
                ret=obj.delete_beginning();
                if(ret==-9999)
                {
                    printf("list is empty");
                }
                else
                {
                    printf("deletion was succesful. deleted value %d \n", ret);
                }
                break;
            }
            case 5:
            {
                int ret;
                ret=obj.delete_end();
                if(ret==-9999)
                {
                    printf("list is empty");
                }
                else
                {
                    printf("deletion was succesful. deleted value %d \n", ret);
                }
                break;
            }
            case 6:
            {
                int ret;
                int pos;
                printf("enter the position. 0 is the first position\n");
                scanf("%d", &pos);
                ret=obj.delete_position(pos);
                if(ret==-9999)
                {
                    printf("list is empty");
                }
                else
                {
                    printf("deletion was succesful. deleted value %d \n", ret);
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
                if (ret>=0)
                {
                    printf("the element was found at %d \n", ret);
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
                int num;
                printf("enter the number of rotations\n");
                scanf("%d", &num);
                int ret;
                ret=obj.rotate(num);
                if (ret==1)
                {
                    printf("rotation was succesful\n");
                }
                else
                {
                    printf("rotation was unsuccesful\n");
                }
                break;
            }
            case 10:
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

//function to insert at the beginning
int listadt::insert_beginning(int num)
{
    if(cur==-1)
    {
        list[0]=num;
        cur++;
        return 1;
    }
    if (cur==4)
    {
        printf("list is full\n");
        return 0;
    }
    for(int i = cur; i>=0;i--)
    {
        list[i+1]=list[i];
    }
    list[0]=num;
    cur++;
    return 1;
}

//function to insert at the end
int listadt::insert_end(int num)
{
    if(cur==-1)
    {
        return insert_beginning(num);
    }
    if (cur==4)
    {
        printf("list is full\n");
        return 0;
    }
    cur++;
    list[cur]=num;
    return 1;
}

//function to insert at a position
int listadt::insert_position(int num, int pos)
{
    if(cur==-1)
    {
        return insert_beginning(num);
    }
    if (cur==4)
    {
        printf("list is full\n");
        return 0;
    }
    if (cur==3)
    {
        return insert_end(num);
    }
    for(int i = cur; i>=pos;i--)
    {
        list[i+1]=list[i];
    }
    list[pos]=num;
    cur++;
    return 1;
}

//function to delete at the beginning
int listadt::delete_beginning()
{
    if(cur==-1)
    {
        return -9999;
    }
    int data = list[0];
    if(cur==0)
    {
        cur=-1;
        list[0]=0;
        return data;
    }
    for (int  i = 1; i<=cur; i++)
    {
        list[i-1]=list[i];
    }
    cur--;
    return data;
}

//function to delete at the end
int listadt::delete_end()
{
    if(cur==-1)
    {
        return -9999;
    }
    if(cur==0)
    {
        return delete_beginning();
    }
    int data=list[cur];
    list[cur]=0;
    cur--;
    return data;
}

//function to delete at a position
int listadt::delete_position(int pos)
{
    if (!(pos<=cur&&pos>=0))
    {
        printf("invalid position was entered\n");
        return -9999;
    }
    if(cur==-1)
    {
        return -9999;
    }
    if(pos==0)
    {
        return delete_beginning();
    }
    if(pos==cur)
    {
        return delete_end();
    }
    int data=list[pos];
    for(int i = pos;i<=cur;i++)
    {
        list[i]=list[i+1];
    }
    cur--;
    return data;
}

//function to search for an element
int listadt::search(int key)
{
    if (cur==-1)
    {
        printf("list is empty\n");
        return -1;
    }
    else
    {
        for (int i = 0; i<=cur; i++)
        {
            if(list[i]==key)
            {
                return i;
            }
        }
    }
    return -1;
}

//function to display
void listadt::display()
{
    if (cur==-1)
    {
        printf("list is empty");
    }
    else
    {
        for (int i = 0; i<=cur; i++)
        {
            printf("%d   ", list[i]);
        }
    }
    printf("\n");
}

//function to rotate the list 
int listadt::rotate(int rot)
{
    if (cur==-1)
    {
        printf("list is empty\n");
        return 0;
    }
    else
    {
        for(int i = 0; i<rot; i++)
        {
            int temp=list[cur];
            for(int j = cur; j>=0; j--)
            {
                list[j]=list[j-1];
            }
            list[0]=temp;
        }
        return 1;
    }
}
