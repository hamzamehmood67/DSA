#include <iostream>
using namespace std;

void mergeSort(int *, int, int);
void merge(int *arr, int l, int mid, int h);
void print(int *, int);

int main()
{
    int arr[5] = {5, 30, 31, 10, 17};
    mergeSort(arr, 0, 4);
    print(arr, 5);
}

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

void merge(int *arr, int l, int mid, int h)
{
    int i = l;
    int j{mid + 1};
    int *newArr = new int[h + 1];
    int k{l};
    while (i <= mid && j <= h)
    {
        if (arr[i] < arr[j])
        {
            newArr[k++] = arr[i++];
        }
        else
        {
            newArr[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        newArr[k++] = arr[i];
        i++;
    }

    while (j <= h)
    {
        newArr[k++] = arr[j];
        j++;
    }

    for (i = l; i <= h; i++)
    {
        arr[i] = newArr[i];
    }
}

void mergeSort(int *arr, int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}