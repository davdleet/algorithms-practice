#include <iostream>
#include <stack>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        stack<int> st;
        string input;
        cin >> input;
        bool result = true;
        for (int i = 0; i < input.size(); i++)
        {
            char current = input[i];
            if (current == '(')
            {
                st.push(1);
            }
            else
            {
                if (!st.size())
                {
                    result = false;
                }
                else
                {
                    st.pop();
                }
            }
        }
        if (st.size())
        {
            result = false;
        }
        if (result)
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
    }
}