#include <iostream>
using namespace std;

void sortZerosOnes(int *, int);
void print(const int *, int);
int main()
{
    int arr[10] = {1, 0, 0, 0, 0, 1, 1, 0, 1, 0};
    sortZerosOnes(arr, 10);
    print(arr, 10);
}

void print(const int *arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

void sortZerosOnes(int *arr, int size)
{
    int i = 0 - 1;

    for (int j = 0; i < size; j++)
    {
        if (arr[j] ==0)
        {
            i += 1;
            swap(arr[i], arr[j]);
        }
    }
}