#include <iostream>
using namespace std;

int *mergeArrays(int *, int, int *, int);
void print(int *, int);

int main()
{
    int arr1[]{5, 5, 5, 6};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[]{1, 3, 4, 6};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int *arr3;
    arr3 = mergeArrays(arr1, size1, arr2, size2);
    int size3 = *(&arr3 + 1) - arr3;
    print(arr3, 9);
    return 0;
}

int *mergeArrays(int *first, int size1, int *second, int size2)
{
    int newSize = size1 + size2;
    int *third = new int[newSize];
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (first[i] < second[j])
        {
            third[k++] = first[i++];
        }
        else if (first[i] > second[j])
        {
            third[k++] = second[j++];
        }
        else
        {
            third[k++] = first[i++];
            j++;
        }
    }

    // Copy remaining elements from the non-empty array

    while (i < size1)
    {
        third[k++] = first[i++];
    }

    while (j < size2)
    {
        third[k++] = second[j++];
    }
    return third;
}
void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }

    cout << endl;
}