#include<iostream>
using namespace std;
 

struct Fraction{
    int num;
    int dnum;
} ;

void print(struct Fraction *ptr)
{
    cout<<ptr->num<<"/"<<ptr->dnum<<endl;
}
 

void print2(struct Fraction *ptrArr[], int size){

    for(int i=0; i<size; i++)
    {
        print(ptrArr[i]);
    }    
}
int main(){
    // int size{};
    // int numinatore{};
    // int dnum{};
    // cout<<"Enter the number of Fractions: "<<endl;
    // cin>>size;
    // Fraction *arr[size];  //to store the fractions
    // for(int i=0; i<size; i++)
    // {
    //     Fraction *fptr=new Fraction();
    //     cout<<"Enter fraction "<<i+1<<" numinatore"<<endl;
    //     cin>>numinatore;
    //     fptr->num=numinatore;
    //     cout<<"Enter fraction "<<i+1<<" denuminatore"<<endl;
    //     cin>>dnum;
    //     fptr->dnum=dnum;
    //     arr[i]=fptr;
    // }
    // print2(arr, size);

    Fraction *ptr=new Fraction();

    ptr->num=2;
    ptr->dnum=3;

    print(ptr);
}