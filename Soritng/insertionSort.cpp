#include <iostream>
using namespace std;

void insertionSort(int *, int);
void print(int *, int);

int main()
{
    int arr[5] = {5, 3, 6, 10, 7};
    insertionSort(arr, 5);
    print(arr, 5);
}

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int curr = arr[i];
        int j = i - 1;

        while (j > -1 && arr[j] > curr)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = curr;
    }
}
