#include <iostream>
using namespace std;

void intersection(int *arr1, int s1, int *arr2, int s2)
{
    int i{};
    int j{};
    while (i < s1 && j < s2)
    {
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i];
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
}

int main()
{
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[4] = {1, 2, 3, 4};
    intersection(arr1, 5, arr2, 4);
}