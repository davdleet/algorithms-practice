#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    queue<int> Q;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            int num;
            cin >> num;
            Q.push(num);
        }
        else if (s == "pop")
        {
            if (!Q.empty())
            {
                int num = Q.front();
                cout << num << endl;
                Q.pop();
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else if (s == "size")
        {
            cout << Q.size() << endl;
        }
        else if (s == "empty")
        {
            if (Q.empty())
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (s == "front")
        {
            if (!Q.empty())
            {
                int num = Q.front();
                cout << num << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else if (s == "back")
        {
            if (!Q.empty())
            {
                int num = Q.back();
                cout << num << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
}