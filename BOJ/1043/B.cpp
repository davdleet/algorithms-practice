#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> know;
vector<vector<int>> ins;
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

    if (know[parent_a])
    {
        parent[parent_b] = parent_a;
    }
    else if (know[parent_b])
    {
        parent[parent_a] = parent_b;
    }
    else
    {
        parent[parent_b] = parent_a;
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    parent = vector<int>(N + 1, -1);
    know = vector<int>(N + 1, 0);
    ins = vector<vector<int>>(M + 1);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int num;
        cin >> num;
        know[num] = 1;
    }
    for (int i = 1; i < N + 1; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        int n;
        cin >> n;
        int first;
        cin >> first;
        ins[i].push_back(first);
        for (int j = 0; j < n - 1; j++)
        {
            int num;
            cin >> num;
            ins[i].push_back(num);
            uni(first, num);
        }
    }
    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        bool lie = true;
        for (int j = 0; j < ins[i].size(); j++)
        {
            int p = find(ins[i][j]);
            if (know[p])
            {
                lie = false;
            }
        }
        if (lie)
        {
            cnt++;
        }
    }
    cout << cnt;
}