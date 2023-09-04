#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp{a};
    a = b;
    b = temp;
}

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void swapAlternative(int *arr, int size)
{
    for (int i = 0; i < size; i = i + 2)
    {
        swap(arr[i], arr[i + 1]);
    }
    print(arr, 4);
}

int main()
{
    int arr[4] = {1, 2, 3, 4};
    swapAlternative(arr, 4);
}