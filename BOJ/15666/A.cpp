#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;
int M;
map<string, int> m;
vector<int> nums;
string s = "";
void DFS(int level, int cnt)
{

    if (cnt == M)
    {
        if (m.find(s) == m.end())
        {
            m[s] = 1;
            s.pop_back();
            cout << s << endl;
        }
    }
    else
    {
        for (int i = level; i < nums.size(); i++)
        {
            int og_size = s.size();
            s = s.append(to_string(nums[i]) + " ");
            DFS(i, cnt + 1);
            s.erase(og_size);
        }
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N >> M;

    nums = vector<int>(N, 0);
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        nums[i] = n;
    }
    sort(nums.begin(), nums.end());

    DFS(0, 0);
}