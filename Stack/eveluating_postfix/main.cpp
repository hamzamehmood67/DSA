#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int isOperand(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int eve(char *postfix)
{
    stack<char> st;

    int i{0};
    int num1{0}, num2{0};
    int result{0};

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
        {
            st.push(postfix[i] - '0');
        }
        else
        {
            num2 = st.top();
            st.pop();
            num1 = st.top();
            st.pop();

            switch (postfix[i])
            {
            case '+':
                result = num1 + num2;
                st.push(result);
                break;
            case '-':
                result = num1 - num2;
                st.push(result);
                break;
            case '*':
                result = num1 * num2;
                st.push(result);
                break;
            case '/':
                result = num1 / num2;
                st.push(result);
                break;

            default:
                break;
            }
        }
    }

    return st.top();
}

int main()
{
    char *postfix = "234*+82/-";
    cout << eve(postfix);
}