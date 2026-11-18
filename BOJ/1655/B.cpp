#include <iostream>
#include <queue>
using namespace std;

int N;

priority_queue<int> mx;
priority_queue<int, vector<int>, greater<int>> mn;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "rt", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (i == 0)
        {
            mx.push(num);
        }
        else
        {
            if (num >= mx.top() && mn.size() < mx.size())
            {
                mn.push(num);
            }
            else
            {
                mx.push(num);
            }
            if (mx.size() && (mx.size() - mn.size()) > 1)
            {
                int move = mx.top();
                mx.pop();
                mn.push(move);
            }
        }
        if (i != 0 && (mx.size() + mn.size()) % 2 == 0)
        {
            cout << min(mx.top(), mn.top()) << "\n";
        }
        else
        {
            cout << mx.top() << "\n";
        }
    }
}