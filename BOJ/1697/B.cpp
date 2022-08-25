#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<pair<int, int>> q;
vector<int> check;

bool visit(int num)
{
    if (num <= 100000 && num >= 0 && !check[num])
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    check = vector<int>(100001, 0);
    int num = N;
    int time = 0;
    q.push({N, 0});
    while (q.size())
    {
        pair<int, int> current = q.front();
        int loc = current.first;
        int t = current.second;
        q.pop();
        if (loc == K)
        {
            time = t;
            break;
        }
        if (visit(loc * 2))
        {
            q.push({loc * 2, t + 1});
            check[loc * 2] = 1;
        }
        if (visit(loc + 1))
        {
            q.push({loc + 1, t + 1});
            check[loc + 1] = 1;
        }
        if (visit(loc - 1))
        {
            q.push({loc - 1, t + 1});
            check[loc - 1] = 1;
        }
    }
    cout << time;
}