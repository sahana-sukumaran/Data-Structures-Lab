//mplementing graph adt using graphacency list

#include <iostream>

#include<list>

using namespace std;

class graphadt 
{

    private:

        int V;                     

        list<int>* graph;             

    public:

        graphadt(int v) 
        {

            V = v;
            graph = new list<int>[V]; 

        }

        bool isvalid(int);
        void insert(int,int);
        void deletion(int,int);
        void search(int,int);
        void display();

};

int main()
{
    int n;
    cout<<("enter the number of vetices:\n");
    cin>>n;
    graphadt obj(n);
    int u,v,chc;
    do{
        cout<<("\nenter\n1.for insertion\n2. for deletion\n3. for search\n4. for display\n5. for exit\n");
        cin>>chc;
        switch(chc)
        {          
            case 1:
            {
                cout<<"enter the two verices between which the edge is to be added: \n";
                int v,u;
                cin>>u;
                cin>>v;

                obj.insert(u,v);

                break;
            }
            case 2:
            {
                cout<<"enter the two verices between which the edge is to be deleted: \n";
                int v,u;
                cin>>u;
                cin>>v;

                obj.deletion(u,v);

                break;
            }
            case 3:
            {
                cout<<"enter the two verices between which the edge is to be searched: \n";
                int v,u;
                cin>>u;
                cin>>v;

                obj.search(u,v);

                break;
            }

            case 4:
            {

                obj.display();

                break;
            }

            case 5:
            {
                exit(0);
            }
            default:
            {

                cout<<("Invalid chc\n");
            }
        }

    }while(chc!=5);

    return 0;

}
bool graphadt:: isvalid(int v) 
{

    return (v >= 0 && v < V);

}


void graphadt::insert(int u,int v)
{

    if(isvalid(u)&&isvalid(v))
    {

        graph[u].push_back(v);

        graph[v].push_back(u);

        cout<<("Edge inserted between %d and %d\n",u,v);

    }

    else
    {
        cout<<("Invalid vertex number\n");

    }

}

void graphadt::deletion(int u,int v)
{

    if(isvalid(u)&&isvalid(v))
    {

        graph[u].remove(v);

        graph[v].remove(u);

        cout<<("Edge deleted between %d and %d\n",u,v);

    }

    else
    {

        cout<<("Invalid vertex number\n");

    }

}

void graphadt::search(int u,int v)
{

    if(isvalid(u)&&isvalid(v))
    {

        bool found=false;

        for(int val:graph[u])
        {

            if(val==v)
            {

                found=true;

                break;

            }

        }

        if(found)
        {

            cout<<("Edge exist between %d and %d\n",u,v);

        }

        else
        {

            cout<<("Edge does not exist between %d and %d\n",u,v);

        }

    }

    else
    {

        cout<<("invalid vertex\n");

    }

}

void graphadt::display()
{

    cout<<("graphACENCY LIST\n");

    for(int i=0;i<V;i++)
    {

        cout<<("%d:",i);

        for(int x:graph[i])
        {

            cout<<("%d ->",x);

        }

        cout<<("\n");

    }

}
