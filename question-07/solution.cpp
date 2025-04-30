
#include <cstdio>
#include <cstdlib>

class listadt 
{
    struct node 
    {
        int data;
        struct node* next;
    } *head;

    struct node* gethead() 
    {
        return head;
    }

    public:
    listadt() 
    {
        head = NULL;
    }

    struct node* callgethead() 
    {
        return gethead();
    }

    int insert(int);
    void merge(listadt&, listadt&);
    void display();
};

int main() 
{
    int chc;
    listadt obj, obj1, obj2;
    do {
        printf("enter: \n\t 1. for inserting\n\t 2. for merging\n\t 3. for displaying\n\t 4. for exit\n");
        printf("enter the choice\n");
        scanf("%d", &chc);

        switch (chc) 
        {
            case 1: 
            {
                int num;
                printf("enter the number to be inserted\n");
                scanf("%d", &num);
                if (obj.insert(num)) 
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
                char opt;
                do 
                {
                    printf("enter the elements of the first list\n");
                    int data;
                    scanf("%d", &data);
                    obj1.insert(data);
                    printf("to stop enter 'n' else enter 'y'\n");
                    scanf(" %c", &opt);
                } while (opt == 'y');

                do 
                {
                    printf("enter the elements of the second list\n");
                    int data;
                    scanf("%d", &data);
                    obj2.insert(data);
                    printf("to stop enter 'n' else enter 'y'\n");
                    scanf(" %c", &opt);
                } while (opt == 'y');

                obj.merge(obj1, obj2);
                printf("Merging was successful\n");
                break;
            }
            case 3:
                obj.display();
                break;
            case 4:
                return 0;
            default:
                printf("invalid input\n");
                break;
        }
    } while (chc < 4);
}

int listadt::insert(int num) 
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) 
    {
        printf("memory allocation failed\n");
        return 0;
    }
    newnode->data = num;
    newnode->next = NULL;

    if (head == NULL || head->data >= num) 
    {
        newnode->next = head;
        head = newnode;
        return 1;
    }

    struct node* temp = head;
    while (temp->next != NULL && temp->next->data < num) 
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    return 1;
}

void listadt::merge(listadt& obj1, listadt& obj2) 
{
    struct node* head1 = obj1.callgethead();
    struct node* head2 = obj2.callgethead();

    head = NULL;
    struct node** tail = &head;

    while (head1 != NULL && head2 != NULL) 
    {
        struct node** smaller = (head1->data <= head2->data) ? &head1 : &head2;
        *tail = *smaller;
        *smaller = (*smaller)->next;
        tail = &((*tail)->next);
    }

    *tail = (head1 != NULL) ? head1 : head2;
}

void listadt::display() 
{
    if (head == NULL)
    {
        printf("list is empty\n");
    } else 
    {
        struct node* temp = head;
        while (temp != NULL) 
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
    }
    printf("NULL\n");
}
