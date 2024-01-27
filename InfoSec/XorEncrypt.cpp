#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void reverseStr(string& str)
{
    int len = str.length();
    int n = len-1;
    int i = 0;
    while(i<=n){
        //Using the swap method to switch values at each index
        swap(str[i],str[n]);
        n = n-1;
        i = i+1;
  }
 
}
 
string  decToBin(int num)
{
    string binary="";

    while(num>0)
    {
        int rem=num%2;
        num/=2;
        binary+=to_string(rem);
    }

    while(binary.length()<8)
        binary+='0';

    reverseStr(binary);

    return binary;
}


string txtToBin(string str)
{
    int size= str.length();
    string binary="";
    for(int i=0; i<size; i++)
    {
        int Ascii=int(str[i]);
        binary+=decToBin(Ascii);
    }

    return binary;


}

void encrypt(string plainTxt, string key)
{
    string plainTxtBin= txtToBin(plainTxt);
    string keyBin=txtToBin(key);
    string chiper="";

    int sizePT=plainTxtBin.length();
    int sizeKey=keyBin.length();
    int j{};
    for(int i=0; i<sizePT ; i++)
    {
        int charPL=int(plainTxtBin[i]);
        int charKey=int(keyBin[j++]);
        int charChip=charPL^charKey;

        chiper+=to_string(charChip);
         j%=sizeKey;
    }
    return chiper;
        
} 

int main(){

  string plainTxt="";
  string key="";
  cout<<"Enter plain text(Text form only)"<<endl;
  cin>>plainTxt;
  cout<<"Enter a Key(Text form only)"<<endl;
  cin>>key;
 
  encrypt(plainTxt,key);

}

