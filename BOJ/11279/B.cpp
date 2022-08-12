#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
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
                int num = pq.top();
                cout << num << "\n";
                pq.pop();
            }
        }
        else
        {
            pq.push(ins);
        }
    }
}