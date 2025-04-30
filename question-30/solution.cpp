//program to implement has ADT using linear probing

#include<iostream>
using namespace std;

class hashadt
{
    int size;
    int* hash;
    public:
    hashadt(int siz)
    {
        size=siz;
        hash = new int[siz];
        for (int i = 0;i<size;i++)
        {
            hash[i]=-1;
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
    int i = 0;
    while(i<size)
    {
        int npos = (pos + i*i +i)%size;
        i++;
        if(hash[npos]==-1||hash[npos]==-2)
        {
            hash[npos]=val;
            return 1;
        }
    }
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
    int i = 0;
    while(i<size)
    {
        int npos = (pos + i*i +i)%size;
        i++;
        if(hash[npos]==val)
        {
            hash[npos]=-2;
            return 1;
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
    if (hash[pos]==val)
    {
        return pos;
    }
    else
    {
        int step = 0;
        while(step<size)
        {
            step++;
            pos=(pos+1)%size;
            if (hash[pos]==val)
            {
                return pos;
            }
        }
    }
    return -1;
}

void hashadt::display()
{
    for(int i = 0;i<size;i++)
    {
        if(hash[i]==-1)
        {
            cout<<i<<": "<<"[EMPTY]\n";
        }
        else if(hash[i]==-2)
        {
            cout<<i<<": "<<"[DELETED]\n";
        }
        else
        {
            cout<<i<<": "<<hash[i]<<"\n";
        }
    }
}
