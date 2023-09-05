#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int isOperand(char s)
{
    if (s == '+' || s == '-' || s == '*' || s == '/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int pre(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    return 0;
}

char *convert(char *infix)
{
    // int size = strlen(infix);
    stack<char> st;
    st.push('#');
    char *postfix = new char[strlen(infix) + 1];

    int i{0};
    int j{0};

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
            // this is coment
        }
        else
        {
            if (pre(infix[i]) > pre(st.top()))
            {
                st.push(infix[i++]);
            }
            else
            {
                postfix[j++] = st.top();
                st.pop();
            }
        }
    }

    while (!st.empty())
    {
        postfix[j++] = st.top();
        st.pop();
    }

    postfix[j] = '\0';
    return postfix;
}

int main()
{

    char *infix = "a+b*c";

    char *postfix = convert(infix);
    cout << postfix;
}
