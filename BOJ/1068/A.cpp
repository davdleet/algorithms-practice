#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> arr;
vector<int> root;
vector<int> temp;
vector<int> line;
int r_node;

int find(int node)
{
    if (root[node] == node)
    {
        return node;
    }
    else
    {
        return root[node] = find(root[node]);
    }
}

void uni(int a, int b)
{
    int parent_a = find(a);
    int parent_b = find(b);
    root[parent_b] = parent_a;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    arr = vector<vector<int>>(N, temp);
    root = vector<int>(N, 0);
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        line.push_back(num);
    }
    cin >> r_node;
    for (int i = 0; i < N; i++)
    {
        root[i] = i;
    }
    for (int i = 0; i < N; i++)
    {
        int num = line[i];
        if (num != -1)
        {
            arr[num].push_back(i);
            if (i != r_node)
            {
                uni(num, i);
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (!arr[i].size())
        {
            if (find(i) != r_node)
            {
                cnt++;
            }
        }
        else
        {
            bool none = true;
            for (int j = 0; j < arr[i].size(); j++)
            {
                if (arr[i][j] != r_node)
                {
                    none = false;
                }
            }
            if (none)
            {
                cnt++;
            }
        }
    }
    cout << cnt;
}