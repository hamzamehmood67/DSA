#include <iostream>
#include <stack>
using namespace std;

bool isBalance(char *exp)
{
    stack<char> st;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            st.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (st.empty())
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }

    if (st.empty())
    {
        return true;
    }
}

int main()
{

    char *exp = "(a+b(a-c)))";

    if (isBalance(exp) == true)
    {
        cout << "Expression is Balance";
    }
    else
    {
        cout << "Expression is not balance";
    }
}
