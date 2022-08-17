#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class edge
{
public:
    int v1, v2, value;
    edge(int a, int b, int v)
    {
        v1 = a;
        v2 = b;
        value = v;
    }
};

bool mysort(edge *a, edge *b)
{
    return a->value < b->value;
}

vector<edge *> arr;
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
    int a_parent = find(a);
    int b_parent = find(b);
    parent[b_parent] = parent[a_parent];
}

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int V, E;
    cin >> V >> E;
    parent = vector<int>(V + 1, 0);
    for (int i = 0; i < E; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        edge *temp = new edge(A, B, C);
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end(), mysort);

    for (int i = 1; i < V + 1; i++)
    {
        parent[i] = i;
    }
    int added = 0;
    int sum = 0;
    for (int i = 0; i < E; i++)
    {
        if (added == V - 1)
        {
            break;
        }
        int a, b, c;
        a = arr[i]->v1;
        b = arr[i]->v2;
        c = arr[i]->value;
        // cycle found
        if (find(a) == find(b))
        {
            continue;
        }
        // no cycle
        else
        {
            uni(a, b);
            sum += c;
        }
    }
    cout << sum;
}