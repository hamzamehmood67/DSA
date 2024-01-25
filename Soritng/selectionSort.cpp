#include <iostream>
using namespace std;

void selectionSort(int *, int);
void print(int *, int);

int main()
{
    int arr[5] = {5, 30, 6, 1, 7};
    selectionSort(arr, 5);
    print(arr, 5);
}

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

void selectionSort(int *arr, int size)
{
    int k{};
    int j{};
    int i{};

    for (i = 0; i < size - 1; i++)
    {
        for (j = k = i; j < size; j++)
        {
            if (arr[j] < arr[k])
                k = j;
        }

        swap(arr[i], arr[k]);
    }
}

