#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find(int child)
{
    if (parent[child] == child)
    {
        return child;
    }
    else
    {
        return parent[child] = find(parent[child]);
    }
}

void uni(int a, int b)
{
    int parent_a = find(a);
    int parent_b = find(b);
    parent[parent_b] = parent_a;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    parent = vector<int>(N + 1, 0);
    for (int i = 1; i < N + 1; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        uni(a, b);
    }
    int last;
    cin >> last;
    last = find(last);
    int cnt = 0;
    for (int i = 1; i < N; i++)
    {
        int num;
        cin >> num;
        int current = find(num);
        if (last != current)
        {
            cnt++;
            last = current;
        }
    }
    cout << cnt;
}