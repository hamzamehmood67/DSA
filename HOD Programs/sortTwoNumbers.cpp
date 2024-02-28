#include<iostream>
using namespace std;
 
void print(const int* arr, int size);
 void sortArr(int *arr, int size);

 
int main(){
    int arr[10]={9,9,9,2,9,2,2,9,9,9};

    sortArr(arr, 10);
    print(arr, 10);
}

void print(const int* arr, int size)
{
    for(int i=0; i<size; i++)
        cout<<arr[i];

    cout<<endl;
}

void sortArr(int *arr, int size)
 {
    int start{-1};
    int mid{-1};
    int pivot=arr[size-1];
    for(int j=0;j<size-1; j++)
    {
        if(arr[j]<pivot)
        {
            mid++;
            start++;
            swap(arr[start], arr[j]);
        }
        else if(arr[j]==pivot)
        {
            mid++;
            swap(arr[mid], arr[j]);
        }
    }

    swap(arr[mid+1], arr[size-1]);
 }