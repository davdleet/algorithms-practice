#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

vector<int> nums;
vector<int> visited;
map<string, int> m;

string print = "";
int M;
void DFS(int level)
{
    if (level >= M)
    {
        if (m.find(print) == m.end())
        {
            m[print] = 1;
            string temp = print;
            temp.pop_back();
            cout << temp << endl;
        }
    }
    else
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (!visited[i])
            {
                visited[i] = 1;
                int prevLength = print.length();
                print += to_string(nums[i]) + " ";
                DFS(level + 1);
                print.erase(prevLength); // Revert print to its previous state
                visited[i] = 0;
            }
            // cout << endl;
        }
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N >> M;
    nums = vector<int>(N, 0);
    visited = vector<int>(N, 0);
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        nums[i] = n;
    }
    sort(nums.begin(), nums.end());
    DFS(0);
}