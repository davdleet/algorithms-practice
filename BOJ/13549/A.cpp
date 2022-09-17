#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dis;
int N, K;

bool bounds(int idx)
{
    if (idx >= 0 && idx <= 100000)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int BFS()
{
    queue<pair<int, int>> q;
    q.push({N, 0});
    int ans = 10000000;
    while (q.size())
    {
        int loc = q.front().first;
        int time = q.front().second;
        q.pop();
        if (loc == K)
        {
            if (time < ans)
            {
                ans = time;
            }
        }
        if (time > dis[loc])
        {
            continue;
        }
        if (bounds(loc + 1) && time + 1 < dis[loc + 1])
        {
            dis[loc + 1] = time + 1;
            q.push({loc + 1, time + 1});
        }
        if (bounds(loc - 1) && time + 1 < dis[loc - 1])
        {
            dis[loc - 1] = time + 1;
            q.push({loc - 1, time + 1});
        }
        if (bounds(loc * 2) && time < dis[loc * 2])
        {
            dis[loc * 2] = time;
            q.push({loc * 2, time});
        }
    }
    return ans;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K;
    dis = vector<int>(100001, 1000000);
    cout << BFS();
}