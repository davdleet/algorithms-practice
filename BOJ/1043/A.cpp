#include <iostream>
#include <map>
#include <vector>

#define MAX_N 51
using namespace std;
int N, M;
int T;
vector<int> parent(MAX_N, 1);

// returns the root element
int find(int num)
{
    int n = num;
    while (n != parent[n])
    {
        n = parent[n];
    }
    return n;
}

void uni(int a, int b)
{
    parent[find(b)] = parent[find(a)];
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin >> N >> M;
    cin >> T;
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    int t_root = 0;
    if (T != 0)
    {
        cin >> t_root;
    }
    for (int i = 1; i < T; i++)
    {
        int t;
        cin >> t;
        uni(t_root, t);
    }

    vector<vector<int>> inputs;
    for (int i = 0; i < M; i++)
    {
        vector<int> temp;
        int party_n;
        cin >> party_n;
        int party_root;
        bool t_found = false;
        for (int j = 0; j < party_n; j++)
        {
            int party_a;
            cin >> party_a;
            temp.push_back(party_a);
        }
        for (int j = 0; j < party_n; j++)
        {
            int mem = temp[j];
            int check = find(mem);
            if (check == t_root)
            {
                t_found = true;
                party_root = check;
            }
        }
        if (!t_found)
        {
            party_root = find(temp[0]);
        }
        for (int j = 0; j < party_n; j++)
        {
            uni(party_root, temp[j]);
        }
        inputs.push_back(temp);
    }
    int ans = 0;
    for (int i = 0; i < inputs.size(); i++)
    {
        if (!t_root)
        {
            ans++;
        }
        else
        {
            bool lie = true;
            for (int j = 0; j < inputs[i].size(); j++)
            {
                if (find(inputs[i][j]) == t_root)
                {
                    lie = false;
                    break;
                }
            }
            if (lie)
            {
                ans++;
            }
        }
    }
    cout << ans;
}