#include <iostream>
#include <vector>
#define INT_MAX 2147483647

using namespace std;
vector<vector<pair<int, int>>> arr;
int treesize;
int current_path = 0;
int shortest_path = INT_MAX;
int visited[21] = {};

void DFS(int num)
{
    if (num == treesize)
    {
        if (current_path < shortest_path)
        {
            shortest_path = current_path;
        }
    }
    else
    {
        for (int i = 0; i < arr[num].size(); i++)
        {
            if (visited[arr[num][i].first] == 0)
            {
                visited[arr[num][i].first] = 1;
                current_path += arr[num][i].second;
                DFS(arr[num][i].first);
                visited[arr[num][i].first] = 0;
                current_path -= arr[num][i].second;
            }
        }
    }
}

int main()
{
    // freopen("input.txt", "rt", stdin);
    int N, M;
    scanf("%d %d", &N, &M);
    treesize = N;
    for (int i = 0; i < N; i++)
    {
        vector<pair<int, int>> temp;
        arr.push_back(temp);
    }
    for (int i = 0; i < M; i++)
    {
        int v1, v2, v3;
        scanf("%d %d %d", &v1, &v2, &v3);
        pair<int, int> temp_pair;
        temp_pair.first = v2;
        temp_pair.second = v3;
        arr[v1].push_back(temp_pair);
    }
    visited[1] = 1;
    DFS(1);
    cout << shortest_path;
}