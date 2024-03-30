#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int M;
vector<int> v;
set<string> visited;
void DFS(vector<int> prev, int level)
{
    if (level == M)
    {
        string line = "";
        for (int num : prev)
            line = line + to_string(num) + " ";
        line.pop_back();
        cout << line << endl;
    }
    else
    {
        int lastPick = (prev.empty()) ? 0 : prev.back();
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] >= lastPick)
            {
                prev.push_back(v[i]);
                DFS(prev, level + 1);
                prev.pop_back();
            }
        }
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, m;
    cin >> N >> m;
    M = m;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    vector<int> start;
    DFS(start, 0);
}