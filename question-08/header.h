#ifndef HEADER_H
#define HEADER_H

class listadt 
{
    struct node 
    {
        int data;
        struct node* next;
    } *head;

    struct node* gethead(); 

    public:
    listadt(); 
    struct node* callgethead()
    {
        return gethead();
    }
    int insert(int);
    void merge(listadt&,listadt&);
    void display(); 
};
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

#endif
