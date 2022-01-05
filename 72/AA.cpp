#include <iostream>
#include <queue>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    int N, K;
    scanf("%d %d", &N, &K);
    queue<int> q;
    for (int i = 1; i <= 8; i++)
    {
        q.push(i);
    }
    while (q.size() > 1)
    {
        for (int i = 0; i < K - 1; i++)
        {
            int temp = q.front();
            q.push(temp);
            q.pop();
        }
        q.pop();
    }
    cout << q.front();
}