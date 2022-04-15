#include <iostream>
#include <queue>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    priority_queue<int> pq;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (num == 0)
        {
            if (pq.size() != 0)
            {
                int top = pq.top();
                pq.pop();
                cout << top << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else
        {
            pq.push(num);
        }
    }
}