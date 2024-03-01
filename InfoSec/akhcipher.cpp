#include <iostream>
#include <string>
#include <array>
#include <bitset>
#include <algorithm>
#include <fstream>

using namespace std;

string XOR(const string &, const string &);
void IP(string &);
void IPInverse(string &);
char Encryption(char, char);
char Decryption(char, char);
char binToChar(const string &);
string decToBin(int);
void reverseStr(string &);

int main(int argc, char *argv[])
{
    string iFile = argv[1];
    string oFile = argv[2];
    char key = argv[3][0];
    char mode = argv[4][0];
    ifstream inputFile(iFile);
    ofstream outputFile(oFile);

    if (mode == 'e')
    {
        char plainTxt{};
        while (inputFile >> plainTxt)
        {
            char cipher = Encryption(plainTxt, key);
            // cout << "Cipher is " << cipher << endl;

            outputFile << cipher;
        }
    }
    else if (mode == 'd')
    {
        char cipherTxt{};
        while (inputFile >> cipherTxt)
        {
            char plain = Decryption(cipherTxt, key);
            // cout << "Cipher is " << cipher << endl;

            outputFile << plain;
        }
    }
    else
    {
        cout << "Wrong Input try again?";
    }

    return 0;
}

char Decryption(char cipher, char key)
{
    string binaryCipher = decToBin(int(cipher));
    string binaryKey = decToBin(int(key));

    string plain = XOR(binaryCipher, binaryKey);
    IPInverse(plain);

    return binToChar(plain);
}

char Encryption(char plainTxt, char key)
{
    string binaryPlain = decToBin(int(plainTxt));
    string binaryKey = decToBin(int(key));

    IP(binaryPlain);
    string cipher = XOR(binaryPlain, binaryKey);

    return binToChar(cipher);
}

string XOR(const string &binaryPlain, const string &binaryKey)
{
    string result;
    for (size_t i = 0; i < binaryPlain.size(); ++i)
    {
        result += ((binaryPlain[i] - '0') ^ (binaryKey[i] - '0')) + '0';
    }
    return result;
}

void IP(string &binary)
{
    // Perform Initial Permutation
    reverseStr(binary);
    binary = binary.substr(4, 4) + binary.substr(0, 4);
}

void IPInverse(string &binary)
{
    // Perform IP Inverse
    reverseStr(binary);
    binary = binary.substr(4, 4) + binary.substr(0, 4);
}

char binToChar(const string &binaryString)
{
    // Convert binary string to char
    bitset<8> bits(binaryString);
    return static_cast<char>(bits.to_ulong());
}

string decToBin(int num)
{
    // Convert decimal to binary string
    return bitset<8>(num).to_string();
}

void reverseStr(string &str)
{
    // Reverse a string
    reverse(str.begin(), str.end());
}
