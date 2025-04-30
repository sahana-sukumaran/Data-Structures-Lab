//implementing hash adt using separate chain

#include<iostream>
#include<list>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

class hashadt
{
    int size;
    node** hash;
    public:
    hashadt(int siz)
    {
        size=siz;
        hash = new node*[siz];
        for (int i = 0;i<size;i++)
        {
            hash[i]=NULL;
        }
    }
    int insert(int);
    int deletion(int);
    int search(int);
    void display();
};

int main()
{
    int chc;
    int size;
    cout<<"enter the size of the hash table\n";
    cin>>size;
    hashadt obj(size);
    while(1)
    {
        cout<<"enter \n\t1. for insert\n\t2. for delete\n\t3. for search\n\t4. for display\n\t5. for exit\n";
        cin>>chc;
        switch(chc)
        {
            case 1:
            {
                int val;
                cout<<"enter the value to be inserted\n";
                cin>>val;
                int ret = obj.insert(val);
                if(ret==0)
                {
                    cout<<"insertion was unsuccessful\n";
                }
                else
                {
                    cout<<"insertion was successful\n";
                }
                break;
            }
            case 2:
            {
                int val;
                cout<<"enter the value to be deleted\n";
                cin>>val;
                int ret = obj.deletion(val);
                if(ret==0)
                {
                    cout<<"deletion was unsuccessful\n";
                }
                else if(ret==-1)
                {
                    cout<<"deletion was unsuccessful. element to be deleted was not found\n";
                }
                else
                {
                    cout<<"deletion was successful\n";
                }
                break;
            }
            case 3:
            {
                int val;
                cout<<"enter the value to be searched\n";
                cin>>val;
                int ret = obj.search(val);
                if(ret==-1)
                {
                    cout<<"element was not found\n";
                }
                else
                {
                    cout<<"element was found at position: "<<ret<<"\n";
                }
                break;
            }
            case 4:
            obj.display();
            {
                break;
            }
            case 5:
            {
                exit(0);
            }
            default:
            {
                cout<<"invalid input\n";
                break;
            }
        }
    }
}

int hashadt::insert(int val)
{
    if (size==0)
    {
        cout<<"hash table has no size\n";
        return 0;
    }
    int pos = val%size;
    node* newnode = new node;
    newnode->data=val;
    newnode->next=hash[pos];
    
    hash[pos]=newnode;
    return 1;
    return 0;
}

int hashadt::deletion(int val)
{
    if (size==0)
    {
        cout<<"hash table has no size\n";
        return 0;
    }
    int pos = val%size;
    if(hash[pos]==NULL)
    {
        return 0;
    }
    else
    {
        node* cur = hash[pos];
        node* prev = NULL;
        while(cur)
        {
            if(cur->data==val)
            {
                if(prev)
                {
                    prev->next=cur->next;
                }
                else
                {
                    hash[pos]=cur->next;
                }
                return 1;
            }
            prev=cur;
            cur=cur->next;
        } 
    }
    return -1;
}

int hashadt::search(int val)
{
    if (size==0)
    {
        cout<<"hash table has no size\n";
        return -1;
    }
    int pos=val%size;
    if (hash[pos]==NULL)
    {
        return -1;
    }
    else
    {
        node* cur  = hash[pos];
        while(cur)
        {
            if(cur->data==val)
            {
                return pos;
            }
            cur=cur->next;
        }
    }
    return -1;
}

void hashadt::display()
{
    for(int i = 0;i<size;i++)
    {
        if(hash[i]==NULL)
        {
            cout<<i<<": "<<"[EMPTY]\n";
        }
        else
        {
            node* cur = hash[i];
            cout<<i<<": ";
            while(cur!=NULL)
            {
                cout<<cur->data<<" -> ";
                cur=cur->next;
            }
            cout<<"null\n";
        }
    }
}
