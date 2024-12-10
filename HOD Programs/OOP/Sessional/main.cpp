#include <iostream>
#include <cstring>
using namespace std;

class CString
{
private:
    int size;
    char *str;
    void copy(char *dest, const char *src);

public:
    CString() : size(0), str(nullptr) {};
    CString(const char *s)
    {
        size = strlen(s);
        str = new char[size + 1];
        copy(str, s);
    }
    CString(const CString &obj)
    {
        str = new char[(obj.size) + 1];
        copy(str, obj.str);
    }

    ~CString()
    {
        delete[] str;
    }

    CString &operator=(const CString &obj)
    {
        if (this != &obj)
        {
            delete[] str;
            str = new char[(obj.size) + 1];
            copy(str, obj.str);
            size = obj.size;
        }

        return *this;
    }

    char &operator[](const int x)
    {
        return str[x];
    }

    char *getString() const
    {
        return str;
    }

    bool ends_with(const char *s) const
    {
        int si = strlen(s);
        cout << size;
        cout << si << endl;
        if (si > size)
            return false;

        cout << "Helo";
        for (int i = si - 1; i >= 0; i--)
        {

            if (str[i] != s[i])
                return false;
        }

        return true;
    }

    friend CString operator+(const CString &left, const CString &right);
    friend ostream &operator<<(ostream &os, const CString &obj);
    friend istream &operator>>(istream &is, CString &str);
};

void CString::copy(char *dest, const char *src)
{
    int i{};
    for (i = 0; i < strlen(src); i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

CString operator+(const CString &left, const CString &right)
{

    char *newStr = new char[((left.size) + (right.size)) + 1];

    for (int i = 0; i < left.size; i++)
    {
        newStr[i] = left.str[i];
    }
    for (int i = 0; i < right.size; i++)
    {
        newStr[(left.size) + i] = right.str[i];
    }

    CString temp(newStr);
    delete[] newStr;
    return temp;
}

ostream &operator<<(ostream &os, const CString &obj)
{
    os << obj.str;
    cout << "function Called" << endl;
    return os;
}

istream &operator>>(istream &is, CString &obj)
{
}

void doSomething(CString str)
{
    cout << str << endl;
}

int main()
{
    CString names[10] = {"Akhuwat", "College", "Kasur"};
    names[4] = names[0] + names[1] + names[2];
    names[4][6] = 'Z';
    // cout << names[4] << endl;
    // int size();
    // doSomething(names[0]);

    // cin >> names[3];
    names[3] = "";
    if (names[3].ends_with("abc123"))
        cout
            << " ends with abc123" << endl;
    else
        cout << names[3] << " does not end with abc123" << endl;

    return 0;
}