#include <iostream>
using namespace std;

int *mergeArrays(int *, int, int *, int);
void print(int *, int);

int main()
{
    int arr1[5]{1, 3, 4, 8, 9};
    int arr2[1]{0};
    int *arr3;
    arr3 = mergeArrays(arr1, 5, arr2, 1);

    print(arr3, 6);
    return 0;
}

/// Fucntions/////////

int *mergeArrays(int *first, int size1, int *second, int size2)
{
    int newSize{size1 + size2};

    int *third = new int[newSize];

    int i{}, j{}, k{};

    while (i < size1 && j < size2)
    {
        if (first[i] < second[j])
            third[k++] = first[i++];

        else
            third[k++] = second[j++];
    }

    while (i < size1)
        third[k++] = first[i++];

    while (j < size2)
        third[k++] = second[j++];

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