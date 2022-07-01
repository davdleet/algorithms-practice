#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);

    int N, M;
    int T;
    cin >> N >> M;
    cin >> T;
    vector<int> know;
    vector<bool> safe(N + 1, 1);
    map<int, int> t;
    vector<map<int, int>> m(N + 1, t);
    if (T)
    {
        for (int i = 0; i < T; i++)
        {
            int num;
            cin >> num;
            know.push_back(num);
            safe[num] = 0;
        }
    }
    vector<vector<int>> inputs;
    for (int i = 0; i < M; i++)
    {
        int n;
        cin >> n;
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int v;
            cin >> v;
            temp.push_back(v);
        }
        inputs.push_back(temp);
        for (int j = 0; j < temp.size(); j++)
        {
            for (int k = 0; k < temp.size(); k++)
            {
                if (j == k)
                {
                    continue;
                }
                m[temp[j]][temp[k]] = 1;
                m[temp[k]][temp[j]] = 1;
            }
        }
    }
    // for (int i = 1; i < m.size(); i++)
    // {
    //     cout << "dictionary " << i << endl;
    //     for (auto it = m[i].begin(); it != m[i].end(); it++)
    //     {
    //         cout << it->first << " : " << it->second << endl;
    //     }
    // }
    // cout << endl;
    for (int i = 1; i < m.size(); i++)
    {
        for (auto it = m[i].begin(); it != m[i].end(); it++)
        {
            int link = it->first;
            if (!safe[link])
            {
                safe[i] = 0;
                for (auto it1 = m[i].begin(); it1 != m[i].end(); it1++)
                {
                    int link1 = it1->first;
                    safe[link1] = 0;
                }
            }
        }
    }
    int ans = 0;
    cout << "inputs" << endl;
    cout << inputs.size() << endl;
    for (int i = 0; i < inputs.size(); i++)
    {
        bool lie = 1;
        cout << i << endl;
        for (int j = 0; j < inputs[i].size(); j++)
        {
            cout << inputs[i][j] << " ";
            // cout << inputs[i][j] << endl;
            if (!safe[inputs[i][j]])
            {
                lie = 0;
                break;
            }
        }
        if (lie)
        {
            // cout << "lie on party " << i << endl;
            ans++;
        }
    }
    cout << "ans: " << ans;
    cout << endl;
    for (int i = 1; i < safe.size(); i++)
    {
        cout << safe[i] << " ";
    }
}