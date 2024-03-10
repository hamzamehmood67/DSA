#include<iostream>
using namespace std;
 void print(const int *arr, int size);
 void sortAnyThree(int *, int);
 int secMax(int* arr, int size);
int main(){
    int arr[10]= {2,0,2,0,1,1};
    sortAnyThree(arr, 6);
    print(arr, 6);
    cout<<secMax(arr, 6);
}
int secMax( int* arr, int size) {
        int maxIndex = 0;
        int secondMaxIndex = -1;

        for (int i = 1; i < size; ++i) {
            if (arr[i] > arr[maxIndex]) {
                secondMaxIndex = maxIndex;
                maxIndex = i;
            } else if (arr[i] < arr[maxIndex]) {
                if (secondMaxIndex == -1 || arr[i] > arr[secondMaxIndex]) {
                    secondMaxIndex = i;
                }
            }
        }

        return secondMaxIndex;
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