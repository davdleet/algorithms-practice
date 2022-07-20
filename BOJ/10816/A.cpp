#include <iostream>
#include <map>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "rt", stdin);
    int N, M;
    cin >> N;
    map<int, int> mp;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        mp[temp]++;
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int temp;
        cin >> temp;
        cout << mp[temp] << " ";
    }
}