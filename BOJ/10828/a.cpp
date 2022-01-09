#include <iostream>
#include <stack>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    stack<int> st;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            int num;
            cin >> num;
            st.push(num);
        }
        else if (s == "pop")
        {
            if (!st.empty())
            {
                int num = st.top();
                cout << num << endl;
                st.pop();
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else if (s == "size")
        {
            cout << st.size() << endl;
        }
        else if (s == "empty")
        {
            if (st.empty())
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (s == "top")
        {
            if (!st.empty())
            {
                int num = st.top();
                cout << num << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
}