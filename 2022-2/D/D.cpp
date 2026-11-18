#include <iostream>
#include <deque>
using namespace std;

deque<char> o_stack;
deque<char> x_stack;

int main()
{
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    string s;
    cin >> s;
    int max = 0;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (c == '(')
        {
            if (x_stack.size())
            {
                x_stack.pop_back();
            }
            else
            {
                o_stack.push_back('(');
            }
        }
        else
        {
            if (o_stack.size())
            {
                o_stack.pop_back();
            }
            else
            {
                x_stack.push_back(')');
            }
        }
        if (x_stack.size() > max)
        {
            max = x_stack.size();
        }
        if (o_stack.size() > max)
        {
            max = o_stack.size();
        }
    }
    if (o_stack.size() || x_stack.size())
    {
        cout << -1;
    }
    else
    {
        cout << max;
    }
}