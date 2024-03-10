#include<iostream>
using namespace std;
 void print(const int *arr, int size);
 void sortAnyThree(int *, int);
 int secMax(int* arr, int size);
int main(){
    int arr[10]= {3,3,3,9,9,3,9,3,9,3};
    sortAnyThree(arr, 10);
    print(arr, 10);
    cout<<secMax(arr, 10);
}

int secMax(int* arr, int size)
{
    int max{0};
    int secMaxx{-1};

    for(int i=0; i<size; i++)
    {
        if(arr[i]>arr[max])
            {
                secMaxx=max;
                max=i;
            }
            else if(secMaxx!=-1 && arr[i]>arr[secMaxx])
            {
                secMaxx=i;
            }
        return secMaxx;
    }
}
void sortAnyThree(int * arr, int size)
{
    int low{};
    int mid{};
    int high=size-2;
    int secondMax=secMax(arr,size);
    swap(arr[secondMax], arr[size-1]);
    
    while(mid<=high)
    {
        if(arr[mid]<arr[size-1])
            swap(arr[mid++], arr[low++]);
        else if(arr[mid]==arr[size-1])
            mid++;
        else
            swap(arr[mid],arr[high--]);
    }
    swap(arr[mid], arr[size-1]);
}

void print(const int *arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}