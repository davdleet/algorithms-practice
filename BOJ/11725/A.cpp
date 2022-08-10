#include <iostream>
#include <vector>

using namespace std;

vector<int> temp;
// adjacency list
vector<vector<int>> arr;
// mark visited nodes
vector<int> visited;
// answers
vector<int> parents;
// visit from the root (1) node
void DFS(int parent, int current)
{
    visited[current] = 1;
    // parent of current is previous node
    parents[current] = parent;
    for (int i = 0; i < arr[current].size(); i++)
    {
        if (!visited[arr[current][i]])
        {
            // visit a connected node if not already visited
            DFS(current, arr[current][i]);
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    arr = vector<vector<int>>(N + 1, temp);
    visited = vector<int>(N + 1, 0);
    parents = vector<int>(N + 1, 0);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    DFS(1, 1);
    for (int i = 2; i <= N; i++)
    {
        cout << parents[i] << "\n";
    }
}