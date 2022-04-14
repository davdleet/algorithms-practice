#include <iostream>
#include <queue>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, M;
    int check[100001] = {0};
    cin >> N >> M;
    queue<pair<int, int>> q;
    q.push({N, 0});
    int ans = 0;
    while (q.size() != 0)
    {
        pair<int, int> current = q.front();
        int num = current.first;
        int cnt = current.second;
        if (num == M)
        {
            ans = cnt;
            break;
        }
        q.pop();
        if ((num + 1) <= 100000 && check[num + 1] == 0)
        {
            q.push({num + 1, cnt + 1});
            check[num + 1] = 1;
        }
        if ((num - 1) >= 0 && check[num - 1] == 0)
        {
            q.push({num - 1, cnt + 1});
            check[num - 1] = 1;
        }
        if ((num * 2) <= 100000 && check[num * 2] == 0)
        {
            q.push({num * 2, cnt + 1});
            check[num * 2] = 1;
        }
    }
    cout << ans;
}