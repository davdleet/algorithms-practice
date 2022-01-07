#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

int main()
{
    char input[30];
    scanf("%s", &input);
    stack<char> stk;
    string valid = "YES";
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '(')
        {
            stk.push('(');
        }
        else if (input[i] == ')' && !stk.empty())
        {
            stk.pop();
        }
        else
        {
            valid = "NO";
            break;
        }
    }
    if (!stk.empty())
    {
        valid = "NO";
    }
    cout << valid;
}