#include <iostream>
using namespace std;

int *mergeArrays(int *, int, int *, int);
int *mergeArraysWithoutDup(int *, int, int *, int);
void print(int *, int);

int main()
{
    int arr1[5]{1, 2, 3, 4, 5};
    int arr2[5]{1, 5, 6, 7, 8};
    int *arr3;
    arr3 = mergeArrays(arr1, 5, arr2, 5);
    int *arr4 = mergeArraysWithoutDup(arr1, 5, arr2, 5);

    print(arr3, 10);
    print(arr4, 10);
    return 0;
}

/// Fucntions/////////

int *mergeArrays(int *first, int size1, int *second, int size2)
{
    int newSize{size1 + size2};

    int *third = new int[newSize];

    int i{}, j{}, k{};

    while (k < newSize)
    {
        if (first[i] > second[j])
        {
            third[k++] = second[j++];
        }
        else if (first[i] < second[j])
        {
            third[k++] = first[i++];
        }
        else
        {
            third[k++] = first[i++];
            third[k++] = second[j++];
        }
    }
    return third;
}

int *mergeArraysWithoutDup(int *first, int size1, int *second, int size2)
{
    int newSize{size1 + size2};

    int *third = new int[newSize];

    int i{}, j{}, k{};

    while (k < newSize)
    {
        if (first[i] > second[j])
        {
            third[k++] = second[j++];
        }
        else if (first[i] < second[j])
        {
            third[k++] = first[i++];
        }
        else
        {
            third[k++] = first[i++];
            // third[k++] = second[j++];
            j++;
        }
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