#include <iostream>
using namespace std;

int *mergeArrays(int *, int, int *, int);
void print(int *, int);

int main()
{
    int arr1[3]{5, 5, 5};
    int arr2[2]{5, 5};
    int *arr3;
    arr3 = mergeArrays(arr1, 3, arr2, 2);

    print(arr3, 5);
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

        else if (first[i] > second[j])
            third[k++] = second[j++];

        else
        {
            if (size1 < size2)
            {
                third[k++] = first[i++];
            }
            else
            {
                third[k++] = second[j++];
            }
        }
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