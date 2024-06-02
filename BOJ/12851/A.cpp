#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, K;
    cin >> N >> K;
    queue<int> q;
    int arr_max = 100001;
    vector<int> dist(arr_max, -1);
    vector<int> count(arr_max, 0);
    dist[N] = 0;
    count[N] = 1;
    q.push(N);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int next : {curr - 1, curr + 1, curr * 2})
        {
            if (next >= 0 && next < arr_max)
            {
                if (dist[next] == -1)
                {
                    dist[next] = dist[curr] + 1;
                    count[next] = count[curr];
                    q.push(next);
                }
                else if (dist[next] == dist[curr] + 1)
                {
                    count[next] += count[curr];
                }
            }
        }
    }

    cout << dist[K] << endl
         << count[K] << endl;
    return 0;
}