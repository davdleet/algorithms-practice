#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    // freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    vector<string> arr;
    for (int i = 0; i < s.size(); i++)
    {
        arr.push_back(s.substr(i, s.size()));
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}