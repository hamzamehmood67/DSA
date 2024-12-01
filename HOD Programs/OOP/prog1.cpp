#include <iostream>
using namespace std;
using namespace std;

class DArray
{
private:
    int *arr;
    int _size;
    int cap;
    void increaseSize();

public:
    DArray() : cap(5), _size(0)
    {
        arr = new int[cap];
    }
    DArray(int);
    DArray(const DArray &);
    DArray &operator=(const DArray &);
    void push_back(int);
    int size() const;
    // void print(ostream&) const;

    int &operator[](int idx)
    {
        if (idx >= _size || idx < 0)
        {
            throw invalid_argument("Error: Invalid Index");
        }
        return arr[idx];
    }

    int operator[](int idx) const
    {
        if (idx >= _size || idx < 0)
        {
            throw invalid_argument("Error: Invalid Index");
        }
        return arr[idx];
    }

    DArray &operator+=(const DArray &);
    // DArray operator +(const DArray& );
    // ~DArray(){
    //     cout<<"Destructor Called"<<endl;
    // }
};

// void DArray::print(ostream& out) const
// {
//     for(int i{}; i<_size ; i++)
//     {
//         arr[i]=5;
//         out<<arr[i];

//     }

// }

DArray &DArray::operator=(const DArray &inArray)
{
    cap = inArray.cap;
    _size = inArray._size;

    delete[] arr;

    arr = new int[cap];

    for (int i = 0; i < _size; i++)
    {
        arr[i] = inArray.arr[i];
    }

    return *this;
}

DArray::DArray(const int num)
{
    cap = num;
    _size = num;
    arr = new int[cap];
    for (int i = 0; i < num; i++)
    {
        arr[i] = num;
    }
}

DArray::DArray(const DArray &inArray) : cap(inArray.cap), _size(inArray._size)
{
    arr = new int[cap];
    for (int i = 0; i < _size; i++)
    {
        arr[i] = inArray.arr[i];
    }
}

int DArray::size() const
{
    return _size;
}

void DArray::push_back(int num)
{
    if (_size == cap)
    {
        increaseSize();
    }

    arr[_size++] = num;
    cout << "Size is: " << _size << " Cap is " << cap << endl;
    cout << endl;
    return;
}

void DArray::increaseSize()
{
    cap = cap * 2;
    int *newArr = new int[cap];
    for (int i{}; i < _size; i++)
    {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    return;
}

ostream &operator<<(ostream &out, const DArray &arr)
{

    for (int i{}; i < arr.size(); i++)
    {
        out << arr[i];
    }
    return out;
}

DArray doSomething(DArray arr)
{
    for (int i{}; i < arr.size(); i++)
    {
        arr[i] = arr[i] + 1;
    }

    return arr;
}

// DArray DArray::operator+(const DArray& obj)
// {
//     int objSize=obj.size();
//     int smallSize=objSize<_size?objSize: _size;
//     DArray temp{objSize>_size?obj: *this};
//     for(int i{}; i<smallSize; i++)
//     {
//         temp[i]=this->arr[i]+obj[i];
//     }
//     return temp;
// }

DArray operator+(const DArray &lhs, const DArray &rhs)
{
    int lhsSize = lhs.size();
    int rhsSize = rhs.size();
    int smallSize = lhsSize < rhsSize ? lhsSize : rhsSize;
    DArray temp = lhsSize > rhsSize ? lhs : rhs;

    for (int i = 0; i < smallSize; i++)
    {
        temp[i] = lhs[i] + rhs[i];
    }
    return temp;
}

DArray &DArray::operator+=(const DArray &obj)
{
    int lhsSize = _size;
    int rhsSize = obj.size();
    int smallSize = lhsSize < rhsSize ? lhsSize : rhsSize;

    for (int i{}; i < smallSize; i++)
    {

        arr[i] = arr[i] + obj[i];
    }

    return *this;
}

int main()
{
    DArray arr1{};
    int num{};
    cin >> num;

    while (num >= 0)
    {
        arr1.push_back(num);
        cin >> num;
    }

    cout << arr1 << endl;
    DArray arr2{arr1};
    arr2 = doSomething(arr1);
    cout << arr2 << endl;
    arr2 += arr1;
    cout << arr2 << endl;
    cout << "----" << endl;

    return 0;
}