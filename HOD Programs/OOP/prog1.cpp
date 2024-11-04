#include<iostream>
using namespace std;
using namespace std;


class DArray{
    private:
    int *arr;
    int _size;
    int cap;
    void increaseSize();

public:

DArray(): cap(5), _size(0) {
    arr= new int[cap];
}

DArray(const DArray&);
DArray& operator =(const DArray&);
void push_back(int);
int size();
void print(){
    for(int i={}; i<_size; i++)
    {
        cout<<arr[i]<< " ";
    }
}

int& operator[](int idx)
{
    if(idx>=_size || idx<0){
        throw invalid_argument("Error: Invalid Index");
    }
    
    return arr[idx];
}
};

DArray& DArray::operator=(const DArray& inArray)
{
     cap=inArray.cap;
    _size=inArray._size;

    delete [] arr;

    arr=new int[cap];

   for(int i = 0; i < _size; i++) {
            arr[i] = inArray.arr[i];
        }

          return *this;
}

 DArray::DArray(const DArray& inArray) : cap(inArray.cap), _size(inArray._size) {
        arr = new int[cap];
        for(int i = 0; i < _size; i++) {
            arr[i] = inArray.arr[i];
        }

      
    }

int DArray::size()
{
    return _size;
}

void DArray::push_back(int num)
{
    if(_size==cap){
        increaseSize();
    }

    arr[_size++]=num;
    cout<<"Size is: "<< _size<<" Cap is "<<cap<<endl;
    print();
    cout<<endl;
    return;
}
 
void DArray::increaseSize(){
    cap=cap*2;
    int *newArr=new int[cap];
    for(int i{}; i<_size; i++)
    {
        newArr[i]=arr[i];
    }

    delete[] arr;
    arr=newArr;
    return ;
}
 
ostream& operator <<(ostream& out, DArray& arr)
{
    
    for(int i=0; i<arr.size(); i++)
    {
        out<<arr[i];
        out<<" ";
    }
    
    return out;
}

DArray doSomething(DArray& arr)
{
    for(int i{}; i<arr.size(); i++)
    {
        arr[i]=arr[i]+1;
    }

    return arr;
}

int main(){
    DArray arr1{};
    int num{};
    cin>>num;

    while(num>=0){
        arr1.push_back(num);
        cin>>num;
    }
  
  cout<<arr1<<endl;
  DArray arr2{arr1};
  cout<<arr2<<endl;
  arr2=doSomething(arr1);
cout<<arr2<<endl;

    return 0;
}