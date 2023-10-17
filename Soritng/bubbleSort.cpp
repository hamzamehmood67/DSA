#include <iostream>
using namespace std;

void bubbleSort(int *, int);
void print(int *, int);

int main()
{
    int arr[5] = {5, 3, 6, 1, 7};
    bubbleSort(arr, 5);
    print(arr, 5);
}

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

void bubbleSort(int *arr, int size)
{
    bool swaped{}; // to check if array is already sorted
    for (int i = 0; i < size - 1; i++)
    {
        swaped = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaped = true;
            }
        }

        if (swaped == false)
            break;
    }
}