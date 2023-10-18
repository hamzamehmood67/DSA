#include <iostream>
using namespace std;

void quickSort(int *, int, int);
void print(int *, int);

int main()
{
    int arr[6] = {5, 30, 6, 1, 7, INT32_MAX};
    quickSort(arr, 0, 5);
    print(arr, 5);
}

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int partioning(int *arr, int start, int end)
{
    int pivot = arr[start];
    int i{start}, j{end};
    do
    {

        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j)
            swap(arr[i], arr[j]);
    } while (i < j);

    swap(arr[start], arr[j]);

    return j;
}

void quickSort(int *arr, int start, int end)
{
    int partition{};
    if (start < end)
    {
        partition = partioning(arr, start, end);
        quickSort(arr, start, partition);
        quickSort(arr, partition + 1, end);
    }
}
