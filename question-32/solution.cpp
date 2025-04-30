//implementing graph adt using adjacency graph

#include <iostream>
using namespace std;
class graphadt
{
    private:
        int graph[100][100];
        int n;
    public:

        graphadt(int V){

            n=V;
            for(int i=0;i<n;i++)
            {

                for(int j=0;j<n;j++)
                {

                    graph[i][j]=0;

                }
            }
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
    cout<<("enter the number of veticess:\n");
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

    //valid check function

    bool graphadt::isvalid(int v)
    {

        return (v>=0&&v<n);

    }

    //Function to insert an edge

    void graphadt:: insert(int u,int v)
    {

        if(isvalid(u)&&isvalid(v)){

            graph[u][v]=1;

            graph[v][u]=1;

            cout<<("Edge inserted between %d and %d\n",u,v);

        }

        else{

            cout<<("Invalid vertex number\n");

        }

    }

    //Function to delete an edge

    void graphadt::deletion(int u,int v)
    {
        if(isvalid(u)&&isvalid(v))
        {
            graph[u][v]=0;
            graph[v][u]=0;
            cout<<("Edge deleted between %d and %d\n",u,v);
        }
        else
        {
            cout<<("Invalid vertex number\n");
        }

    }

    //Function to search an edge

    void graphadt::search(int u,int v)
    {
        if(isvalid(u)&&isvalid(v))
        {
            if(graph[u][v]==1)
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

    //Function to dispaly the graph

    void graphadt::display()
    {

        cout<<("ADJACENCY graph\n");

        for(int i=0;i<n;i++)
        {

            for(int j=0;j<n;j++)
            {

                cout<<("%d  ",graph[i][j]);
            }

            cout<<("\n");

        }

    }
