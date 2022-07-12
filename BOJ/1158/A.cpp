#include <iostream>
#include <vector>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    int N, K;
    cin >> N >> K;
    vector<int> arr(N, 0);
    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
        cout << arr[i] << endl;
    }
    int cnt = 0;
    int idx = 0;
    int k = 1;
    while (cnt != N)
    {
        if (k == K)
        {
            int remove;
            remove = arr[idx];
            ans.push_back(remove);
            arr.erase(arr.begin() + idx);
            k = 1;
            cnt++;
            continue;
        }
        if (idx == arr.size())
        {
            idx = 0;
        }
        else
        {
            idx++;
        }
        k++;
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}