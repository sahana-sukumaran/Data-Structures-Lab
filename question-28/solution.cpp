//implementing priority queue using max tree

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>    
using namespace std;
class treeadt
{
    int cur;
    int tree[50];
    public:
    treeadt()
    {
        cur=-1;
        for(int i = 0; i<50; i++)
        {
            tree[i]=0;
        }
    }
    void insert(int);
    bool search(int, int);
    int deletion();
    void heapify_down();
    void heapify_up();
    void display();
    int* heap_sort(int &size);
    bool isempty();
};

int main()
{
    int chc;
    treeadt obj;
    do 
    {
        cout<<("enter: \n\t 1. for inserting\n\t 2. deletion\n\t 3. display\n\t 4. search\n\t 5. sort(heap sort)\n\t 6. exit\n");
        cout<<("enter the choice\n");
        cin>>chc;
        switch(chc)
        {
            case 1:
            {
                int val;
                cout<<("enter the integer to be inserted\n");
                cin>>val;
                int ret;
                obj.insert(val);
                break;
            }
            case 2:
            {
                int ret=obj.deletion();
                if(ret!=-9999)
                {
                    cout<<"deletion successful. deleted element "<<ret<<"\n";
                }
                break;
            }
            case 3:
            {
                obj.display();
                break;
            }
            case 4:
            {
                int key;
                cout<<"enter the element to be searched \n";
                cin>>key;
                bool ret = obj.search(1, key);
                if (ret == false)
                {
                    cout<<"the element was not found\n";
                }
                else
                {
                    cout<<"the element was found\n";
                }
                break;
            }
            case 5:
            {
                int size;
                int* arr = obj.heap_sort(size);
                if (arr==NULL)
                {
                    break;
                }
                for(int i = 1;i<=size;i++)
                {
                    cout<<arr[i]<<"  ";
                }
                cout<<"\n";
                break;
            }
            case 6:
            {
                exit(0);
                break;
            }
            default:
            {
                cout<<"invalid input\n";
            }
        }
    }while(1);
}

bool treeadt::isempty()
{
    if(cur==-1)
    {
        return true;
    }
    else
    {
        return false;
    }

}
void treeadt::insert(int data)
{
    if(cur==-1)
    {
        tree[1]=data;
        cur=1;
    }
    else
    {
        cur++;
        tree[cur]=data;
        heapify_up();
    }
}
void treeadt::heapify_up()
{
    int i = cur;
    while(tree[i/2]<tree[i]&&i>1)
    {
        int temp = tree[i/2];
        tree[i/2] = tree[i];
        tree[i] = temp;
        i=i/2;
    }
}

int treeadt::deletion()
{
    if(cur==-1)
    {
        cout<<"queue is empty\n";
        return -9999;
    }
    else
    {
        int data=tree[1];
        tree[1]=tree[cur];
        cur--;
        heapify_down();
        return data;
    }
}
void treeadt::heapify_down()
{
    int i = 1;
    while(2*i<=cur)
    {
        int lar = i;
        int left=2*i;
        int right=2*i+1;
        if (left<=cur&&tree[left]>tree[lar])
        {
            lar=left;
        }
        if(right<=cur&&tree[right]>tree[lar])
        {
            lar=right;
        }
        if (lar!=i)
        {
            int temp=tree[i];
            tree[i]=tree[lar];
            tree[lar]=temp;
        }
        else
        {
            break;
        }
    }
    
}
void treeadt::display()
{
    if(cur==-1)
    {
        cout<<"queue is empty\n";
        return;
    }
    cout<<"prioprity queue: \n";
    for(int i = 1; i<=cur; i++)
    {
        cout<<tree[i]<<"  ";
    }
    cout<<"\n";
}

bool treeadt::search(int i, int key) 
{
    if (i > cur) 
    {
        return false;
    }
    if (tree[i] < key) 
    {
        return false;
    }
    if (tree[i] == key) 
    {
        return true;
    }
    int left = 2*i;
    int right = 2*i+1;

    return search(left, key) || search(right, key);
}

int* treeadt::heap_sort(int &size)
{
    if (cur==-1)
    {
        cout<<"queue is empty\n";
        return NULL;
    }
    size=cur;
    int i = cur;
    int* arr = new int[cur];
    while(!(isempty()))
    {
        arr[i]=deletion();
        i--;
    }
    return arr;
}
