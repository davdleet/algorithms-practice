#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int, vector<int>, greater<int>> pq;
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (num == 0)
        {
            if (pq.size() == 0)
            {
                cout << 0 << "\n";
            }
            else
            {
                int min = pq.top();
                cout << min << "\n";
                pq.pop();
            }
        }
        else
        {
            pq.push(num);
        }
    }
}