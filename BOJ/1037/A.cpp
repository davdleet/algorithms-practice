#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    vector<int> arr;
    int N;
    cin >> N;
    int first;
    int last;
    if (N == 1)
    {
        int num;
        cin >> num;
        cout << num * num;
        return 0;
    }
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    cout << arr[0] * arr[arr.size() - 1];
}