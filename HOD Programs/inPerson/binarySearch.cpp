

#include<iostream>
using namespace std;
 
int firstOccu(const int *arr, int size, int key);
int lastOccurance(const int *arr, int size, int key);


// Given a list of sorted integers and a ‘key’, find and return the index of the first integer that is not less than the ‘key’. If no such integer exists, return the index at which this ‘key’ would have been if it were in the list 
int insertPosition(const int *arr, int size, int key)
{
    int start{};
    int end{size-1};
    int idx{-1};
    while(start<=end)
    {
        int mid= start+(end-start)/2;

        if(key==arr[mid])
        {
        //    if(mid !=0 && arr[mid-1] !=arr[mid])
        //    {
        //      return mid;
        //    }
        //    else{
        //         end=mid-1;
        //    }

            idx=mid;
            end=mid-1;
        }
        else if(key<arr[mid])
        {
            end= mid-1;
        }
        else{
            start=mid+1;
        }
    }
    if(idx!=-1)
        return idx;
    return start;
}

// Given a list of sorted integers and a ‘key’, find and return the index of the first integer that is greater than the ‘key’. If no such integer exists, return -1.  The complexity shall be O(logn).


int firstGreater(const int *arr, int size, int key)
{
    int start{};
    int end{size-1};

    while(start<=end)
    {
        int mid= start+(end-start)/2;

        if(key==arr[mid])
        {
            start=mid+1;
        }
        else if(key<arr[mid])
        {
            end= mid-1;
        }
        else{
            start=mid+1;
        }
    }

   
     return (start>=size)?-1:start;
}




int count(const int *arr, int size, int key)
{
    int first= firstOccu(arr, size, key);
    int last=lastOccurance(arr, size, key);
    if(first==-1)
        return 0;

    return (last-first)+1;
}

 
int main(){
    int arr[8]={2, 2, 2, 2, 4, 5, 5, 7};
    int target=6;

    // cout<<insertPosition(arr, 8, target);
    cout<<firstGreater(arr, 8, target);
    // cout<<firstOccu(arr, 7, target);
    // cout<<lastOccurance(arr, 7, 9);

    // cout<<count(arr, 7, target);

}




int firstOccu(const int *arr, int size, int key){
    int start{};
    int end{size-1};
    int idx{-1};
    
    while(start<=end)
    {
        int mid=start+(end-start)/2;

        if(arr[mid]==key)
        {
            idx=mid;
            end=mid-1;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }

    return idx;
}

int lastOccurance(const int *arr, int size, int key){
    int start{};
    int end{size-1};
    int idx{-1};
    
    while(start<=end)
    {
        int mid=start+(end-start)/2;

        if(arr[mid]==key)
        {
            idx=mid;
           start=mid+1;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }

    return idx;
}