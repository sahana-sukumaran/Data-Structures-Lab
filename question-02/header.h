//sorting the given array using bullble or insertion or selection sort

#include <iostream>
using namespace std;

void bubble(int[], int);
void selection(int[], int);
void insertion(int[],int);

//bubble sort 
void bubble(int* arr, int num)
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
void selection(int* arr, int num)
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
void insertion(int* arr, int num)
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
