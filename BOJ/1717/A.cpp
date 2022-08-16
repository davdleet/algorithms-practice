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
    int parent_a, parent_b;
    parent_a = find(a);
    parent_b = find(b);
    if (parent_a <= parent_b)
    {
        parent[parent_b] = parent_a;
    }
    else
    {
        parent[parent_a] = parent_b;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int N, M;
    cin >> N >> M;
    parent = vector<int>(N + 1, 0);
    for (int i = 1; i < N + 1; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // union
        if (!a)
        {
            uni(b, c);
        }
        // find
        else
        {
            if (find(b) == find(c))
            {
                cout << "YES"
                     << "\n";
            }
            else
            {
                cout << "NO"
                     << "\n";
            }
        }
    }
}