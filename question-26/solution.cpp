//making an unique array by eleminating left most elements

#include <iostream>
#include <queue>

using namespace std;

void input();
int find(int[], int);

int main()
{
    input();
}

void input()
{
    int test=0;
    cout<<"enter the number of test cases\n";
    cin>>test;

    if(test < 1 || test > 10000) return;

    for (int i=0;i<test;i++)
    {
        int size=0;
        cout<<"enter the number of elements\n";
        cin>>size;

        if(size < 1 || size > 200000) return;

        int arr[size];
        for (int j = 0;j<size;j++)
        {
            int temp;
            cout<<"enter the number at "<<(j+1)<<": ";
            cin>>arr[j];
            if(arr[j] < 1 || arr[j] > size) return;
        }
        int ret=find(arr,size);
        cout<<ret<<"\n";
    }
}

int find(int arr[], int size)
{
    int flag=-1;
    for(int i = size-1; i>=0;i--)
    {
        for(int j = 0; j<i;j++)
        {
            if (arr[i]==arr[j])
            {
                if (flag<j)
                {
                    flag=j;
                }
            }
        }
    }
    return flag+1;
}
