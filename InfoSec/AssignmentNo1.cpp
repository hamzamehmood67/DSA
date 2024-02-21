#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void IP(char *);
char Encryption(char, char);
void reverseStr(string &);
string decToBin(int);

int main()
{
    char plainTxt = 'B';
    char key = 'z';
    char chiper = Encryption(plainTxt, key);
    // char bin[] = "12345678";

    return 0;
}

char Encryption(char plainTxt, char key)
{
    int asciPlain = int(plainTxt);
    int asciKey = int(key);
    char binaryPlain[8];
    char binaryKey[8];
    string binaryP = decToBin(asciPlain);
    string binaryK = decToBin(asciPlain);

    for (int i = 0; i < binaryP.size(); i++)
    {
        binaryPlain[i] = binaryP[i];
        binaryKey[i] = binaryK[i];
    }
    int i{3};
    int j{7};
    /// Performing first Operation of rearranging bits
    while (i >= 0)
    {
        swap(binaryPlain[i--], binaryPlain[j--]);
    }
    /// Performing initial Permutation on Binary
    IP(binaryPlain);
    for (int i = 0; i < 8; i++)
        cout << binaryPlain[i];

    return 'z';
}

/// HELPER FUNCTIONS///////

void IP(char *binary)
{
    char *newBinary = new char[8];
    newBinary[0] = binary[7];
    newBinary[1] = binary[5];
    newBinary[2] = binary[3];
    newBinary[3] = binary[1];
    newBinary[4] = binary[6];
    newBinary[5] = binary[4];
    newBinary[6] = binary[2];
    newBinary[7] = binary[0];

    for (int i = 0; i < 8; i++)
        binary[i] = newBinary[i];

    delete[] newBinary;
}

string decToBin(int num)
{
    string binary = "";

    while (num > 0)
    {
        int rem = num % 2;
        num /= 2;
        binary += to_string(rem);
    }

    while (binary.length() < 8)
        binary += '0';

    reverseStr(binary);

    return binary;
}

void reverseStr(string &str)
{
    int len = str.length();
    int n = len - 1;
    int i = 0;
    while (i <= n)
    {
        // Using the swap method to switch values at each index
        swap(str[i], str[n]);
        n = n - 1;
        i = i + 1;
    }
}