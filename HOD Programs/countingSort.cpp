#include<iostream>
using namespace std;
 void print(const int *arr, int size);
 void countSort(int *A, int* B,int size, int k);
 
int main(){
    int arr[7]={1,2,8,7,3,2,0}; 
    int arr2[7];
  for(int i=0; i<7; i++)
    arr2[i]=0;
    

    countSort(arr, arr2,7, 8);
    print(arr2, 7);

}

void countSort(int* A, int * B,int size, int k)
{
    int *C= new int[k+1];

    for(int i=0; i<=k; i++)
    {
        C[i]=0;
    }

    for(int i=0; i<size; i++)
    {
        C[A[i]]+=1;
    }
    for(int i=1; i<=k ;i++)
    {
        C[i]+=C[i-1];
    }

    for(int i=size-1; i>=0; i--)
    {
        B[C[A[i]]-1]=A[i];
        C[A[i]]--;
    }
}

void print(const int *arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}