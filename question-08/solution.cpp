#include <cstdio>
#include <cstdlib>
#include "header.h"

listadt::listadt() 
{
    head = NULL;
}

struct listadt::node* listadt::gethead()
{
    return head;
}
int insert_list1(int , listadt& );
int insert_list2(int , listadt& );
void merge_2(listadt& , listadt& , listadt& );
int main() 
{
    int chc;
    listadt obj, obj1, obj2;
    do {
        printf("enter: \n\t 1. for inserting into list 1\n\t 2. for inserting into list 2\n\t 3. for merging\n\t 4. for display\n\t 5. for exit\n");
        printf("enter the choice\n");
        scanf("%d", &chc);

        switch (chc) 
        {
            case 1: 
            {
                int num;
                printf("enter the number to be inserted\n");
                scanf("%d", &num);
                if (insert_list1(num, obj1)==1) 
                {
                    printf("insertion was successful\n");
                } else 
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
                if (insert_list2(num, obj2)) 
                {
                    printf("insertion was successful\n");
                } else 
                {
                    printf("insertion was unsuccessful\n");
                }
                break;
            }
            case 3:
                merge_2(obj1,obj2, obj);
                break;
            case 4:
                obj.display();
            case 5:
                return 0;
            default:
                printf("invalid input\n");
                break;
        }
    } while (chc!=5);
}

int insert_list1(int num, listadt& obj1)
{
    return obj1.listadt::insert(num);
}
int insert_list2(int num, listadt& obj2)
{
    return obj2.listadt::insert(num);
}
void merge_2(listadt& obj1, listadt& obj2, listadt& obj)
{
    obj.merge(obj1, obj2);
}
