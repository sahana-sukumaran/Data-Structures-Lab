//searching for an element using linear and binary search
#include <iostream>
#include "sortheader.h"

using namespace std;

int linear(int[], int, int);
int binary(int[], int, int);

int main()
{
    int key;
    cout<<"enter the element to be searched"<<endl;
    cin>>key;
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
        cout<<"\nenter 1. for linear search 2. for binary search, 3. for exit"<<endl;
        cin>>chc;
        switch(chc)
        {
            case 1:
                if(linear(arr,num, key)==0)
                {
                    cout<<"element was not found";
                }
                else
                {
                    cout<<"element was found";        
                }
                break;
            case 2:
                if(binary(arr,num, key)==0)
                {
                    cout<<"element was not found";
                }
                else
                {
                    cout<<"element was found";        
                }
                break;
            case 3:
                return 0;
            default:
                cout<<"invalid input. please enter a valid choice"<<endl;

        }
    }while(chc!=4);
   
    return 0;
}

//linear search
int linear(int arr[], int num, int key)
{
    for(int i = 0; i<num; i++)
    {
        if(arr[i] == key)
        {
            return 1;
        }
    }
    return 0;
}

//binary search
int binary(int arr[], int num, int key)
{
    bubble(arr,num);
    int low = 0;
    int upp = num-1;
    int mean = (upp+low)/2;
    while(low<=upp)
    {
        mean = (upp+low)/2;
        if(arr[mean]==key)
        {
            return 1;
        }
        else if(arr[mean]>key)
        {
            upp=mean-1;
        }
        else
        {
            low=mean+1;
        }
    }
    return 0;
}
