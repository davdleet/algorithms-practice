#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    priority_queue<int, vector<int>, greater<int>> pq;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int ins;
        cin >> ins;

        if (ins == 0)
        {
            if (!pq.size())
            {
                cout << 0 << "\n";
            }
            else
            {
                int print;
                print = pq.top();
                pq.pop();
                cout << print << "\n";
            }
        }
        else
        {
            pq.push(ins);
        }
    }
}