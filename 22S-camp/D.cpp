#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> st1;
stack<int> st2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("D.txt", "rt", stdin);
    int N;
    bool error = false;
    cin >> N;
    string line;
    cin >> line;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (error)
        {
            break;
        }
        char c = line[i];
        if ((c - '0') <= 9 && (c - '0') > 0)
        {
            cnt++;
        }
        else
        {
            if (c == 'L')
            {
                st1.push(c);
            }
            else if (c == 'R')
            {
                if (st1.size())
                {
                    cnt++;
                    st1.pop();
                }
                else
                {
                    error = true;
                }
            }
            else if (c == 'S')
            {
                st2.push(c);
            }
            else if (c == 'K')
            {
                if (st2.size())
                {
                    cnt++;
                    st2.pop();
                }
                else
                {
                    error = true;
                }
            }
        }
    }
    cout << cnt;
}