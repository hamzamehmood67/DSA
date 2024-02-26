#include <bits/stdc++.h>

using namespace std;

string XOR(char *, char *);
void IP(char *);
void IPInverse(char *);
char Encryption(char, char);
char Decryption(char, char);
void reverseStr(string &);
string decToBin(int);
char binToChar(string);

int main()
{
    char plainTxt = 'a';
    char key = 'Z';
    char chiper = Encryption(plainTxt, key);
    cout << "Chiper is " << chiper << endl;

    char Plain = Decryption(chiper, key);
    return 0;
}
char Decryption(char chiper, char key)
{
    string plainT{};
    char plainTxt[8];
    char binaryChiper[8];
    char binaryKey[8];
    string binaryC = decToBin(int(chiper));
    string binaryK = decToBin(int(key));
    for (int i = 0; i < binaryC.size(); i++)
    {
        binaryChiper[i] = binaryC[i];
        binaryKey[i] = binaryK[i];
    }
    // cout << "Chiper in Dec ";
    // for (int i = 0; i < 8; i++)
    //     cout << binaryChiper[i];
    // cout << endl;
    // cout << "Key in Dec ";
    // for (int i = 0; i < 8; i++)
    //     cout << binaryKey[i];
    // cout << endl;

    plainT = XOR(binaryChiper, binaryKey);
    for (int i = 0; i < 8; i++)
        plainTxt[i] = plainT[i];

    IPInverse(plainTxt);

    int i{5};
    int j{0};

    /// Performing first Operation of rearranging bits
    while (i <= 8)
    {
        swap(plainTxt[i++], binaryPlain[j++]);
    }
    // for (int i = 0; i < 8; i++)
    // {
    //     cout << plainTxt[i];
    // }
    // cout << endl;
}
char Encryption(char plainTxt, char key)
{
    char binaryPlain[8];
    char binaryKey[8];
    string chiper{};
    int asciPlain = int(plainTxt);
    int asciKey = int(key);

    string binaryP = decToBin(asciPlain);
    string binaryK = decToBin(asciKey);

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

    // Performing XOR operation on Plain text and KEY
    chiper = XOR(binaryPlain, binaryKey);

    for (size_t i = 0; i < 8; i++)
    {
        cout << chiper[i];
    }
    cout << endl;
    // cout << chiper.size();
    // Converting CipherBinary back to character
    return binToChar(chiper);
    // return 'z';
}

/// HELPER FUNCTIONS///////

string XOR(char *binaryPlain, char *binaryKey)
{

    string chiper{};
    for (int i = 0; i < 8; i++)
    {
        chiper += ((binaryPlain[i] - '0') ^ (binaryKey[i] - '0')) + '0';
    }

    return chiper;
}

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
void IPInverse(char *binary)
{
    char *newBinary = new char[8];
    newBinary[0] = binary[7];
    newBinary[1] = binary[3];
    newBinary[2] = binary[6];
    newBinary[3] = binary[2];
    newBinary[4] = binary[5];
    newBinary[5] = binary[1];
    newBinary[6] = binary[4];
    newBinary[7] = binary[0];

    for (int i = 0; i < 8; i++)
        binary[i] = newBinary[i];

    delete[] newBinary;
}

char binToChar(string binaryString)
{
    // Check if the binary string has 8 digits
    if (binaryString.size() != 8)
    {
        cout << "Binary string must be 8 digits long." << endl;
        return '\0';
    }

    // Convert binary string to integer
    int asciiValue = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (binaryString[i] == '1')
        {
            asciiValue |= (1 << (7 - i)); // Set the corresponding bit in asciiValue
        }
        else if (binaryString[i] != '0')
        {
            cout << "Invalid binary digit: " << binaryString[i] << endl;
            return '\0';
        }
    }

    // Convert ASCII value to character
    return static_cast<char>(asciiValue);
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