#include <iostream>
#include <deque>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 0;
    cin >> N;
    deque<int> arr;
    deque<int> used;
    deque<int> ans;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        used.push_back(temp);
        arr.push_back(i + 1);
    }
    for (int i = N - 1; i > -1; i--)
    {
        if (used[i] == 1)
        {
            ans.push_front(arr[0]);
            arr.erase(arr.begin());
        }
        else if (used[i] == 2)
        {
            ans.insert(ans.begin() + 1, arr[0]);
            arr.erase(arr.begin());
        }
        else if (used[i] == 3)
        {
            ans.push_back(arr[0]);
            arr.erase(arr.begin());
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}