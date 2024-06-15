#include<iostream>
using namespace std;
 
//Write a function(Fibonacci) that accepts a positive number and  returns the corresponding Fibonacci number.

void fab(int num)
{
    int t1=1;
    int t2=1;
    int t3{};
    for(int i=3; i<=num; i++)
    {
        t3=t1+t2;
        
        t1=t2;
        t2=t3;

        cout<<t3<<endl;
    }
} 
 
int main(){

    fab(7);
    return 0;
}