#include <iostream>
#include <unordered_map>
#include <ctype.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int N, M;
    cin >> N >> M;
    unordered_map<int, string> dict;
    unordered_map<string, int> r_dict;
    for (int i = 1; i <= N; i++)
    {
        string temp;
        cin >> temp;
        dict.insert({i, temp});
        r_dict.insert({temp, i});
    }
    for (int i = 0; i < M; i++)
    {
        string query;
        cin >> query;
        if (isdigit(query[0]))
        {
            int q = atoi(query.c_str());
            cout << dict.find(q)->second << '\n';
        }
        else
        {
            cout << r_dict.find(query)->second << '\n';
        }
    }
}