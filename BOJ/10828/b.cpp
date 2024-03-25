#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    deque<int> st;
    for (int i = 0; i < N; i++)
    {
        string command;
        cin >> command;
        if (command == "push")
        {
            int x;
            cin >> x;
            st.push_back(x);
        }
        else if (command == "pop")
        {
            if (!st.size())
            {
                cout << -1 << endl;
            }
            else
            {
                int top;
                top = st.back();
                st.pop_back();
                cout << top << endl;
            }
        }
        else if (command == "size")
        {
            cout << st.size() << endl;
        }
        else if (command == "empty")
        {
            if (!st.size())
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (command == "top")
        {
            if (!st.size())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << st.back() << endl;
            }
        }
    }
}