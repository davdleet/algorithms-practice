#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Data
{
    int money;
    int time;
    Data(int m, int t)
    {
        money = m;
        time = t;
    }
    bool operator<(Data &d)
    {
        return time > d.time;
    }
};

int main()
{
    int res = 0;
    // freopen("input.txt", "rt", stdin);
    int MAX = -2147000000;
    int N;
    scanf("%d", &N);
    vector<Data> arr;
    priority_queue<int> Q;
    for (int i = 0; i < N; i++)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        arr.push_back(Data(v1, v2));
        if (v2 > MAX)
        {
            MAX = v2;
        }
    }
    sort(arr.begin(), arr.end());
    int j = 0;
    for (int i = MAX; i >= 1; i--)
    {
        for (; j < N; j++)
        {
            if (arr[j].time < i)
            {
                break;
            }
            else
            {
                Q.push(arr[j].money);
            }
        }
        if (!Q.empty())
        {
            int top = Q.top();
            res += top;
            Q.pop();
        }
    }
    cout << res;
}