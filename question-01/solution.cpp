//sorting the given array using bullble or insertion or selection sort

#include <iostream>
using namespace std;

void bubble(int[], int);
void selection(int[], int);
void insertion(int[],int);

int main()
{
    int num=0;
    cout<<"the number of elements"<<endl;
    cin>>num;
    cout<<"enter the elements in the array"<<endl;
    int arr[num];
    for (int i = 0; i<num; i++)
    {
        cin>>arr[i];
    }
    int chc=0;
    do
    {
        cout<<"\nenter 1. for bubble sort 2. for selection sort, 3.for insertion sort, 4. for exit"<<endl;
        cin>>chc;
        switch(chc)
        {
            case 1:
                bubble(arr,num);
                cout<<"sorted array: "<<endl;
                for(int i =0; i<num; i++)
                {
                    cout<<arr[i];
                    cout<<"  ";
                }
                break;
            case 2:
                selection(arr,num);
                cout<<"sorted array: "<<endl;
                for(int i =0; i<num; i++)
                {
                    cout<<arr[i];
                    cout<<"  ";
                }
                break;
            case 3:
                insertion(arr,num);
                cout<<"sorted array: "<<endl;
                for(int i =0; i<num; i++)
                {
                    cout<<arr[i];
                    cout<<"  ";
                }
                break;
            case 4:
                return 0;
            default:
                cout<<"invalid input. please enter a valid choice"<<endl;

        }
    }while(chc!=4);
   
    return 0;
}

//bubble sort 
void bubble(int arr[], int num)
{
    int temp = 0;
    for(int i = 0;i<num;i++)
    {
        for(int j = 0; j<num-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

//selection sort
void selection(int arr[], int num)
{
    for(int i = 0; i<num; i++)
    {
        int temp = arr[i];
        int pos = i;
        for(int j = i+1; j<num; j++)
        {
            if(arr[j]<temp)
            {
                temp = arr[j];
                pos = j;
            }
            arr[pos] = arr[i];
            arr[i] = temp;
        }
    }
}

//insertion sort
void insertion(int arr[], int num)
{
    for(int i = 1; i<num; i++)
    {
        int temp = arr[i];
        int pos = i;
        while(pos>0&&arr[pos-1]>temp)
        {
            arr[pos] = arr[pos-1];
            pos--;
        }
        arr[pos] = temp;
    }
}
