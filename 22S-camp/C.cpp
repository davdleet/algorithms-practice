#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;

int main()
{
    freopen("C.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int P, N;
    cin >> P >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (P >= 200)
        {
            break;
        }
        int p = arr[i];
        P = P + p;
        cnt++;
    }
    cout << cnt;
}