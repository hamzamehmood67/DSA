#include <iostream>
using namespace std;

void bubbleSort(int *, int);
void print(int *, int);

int main()
{
    int arr[11] = {5, 3, 6, 10, 72,1,4,7,6,0,1};
    bubbleSort(arr,11);
    print(arr,11);
}

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

void bubbleSort(int *arr, int size)
{
    bool swaped{};
    for (int i = 0; i < size ; i++)
    {
        swaped = false;
        for (int j = 0; j < size - i; j++)
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