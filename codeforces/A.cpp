#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int tc;
    cin >> tc;
    for (int t = 0; t < tc; t++)
    {
        int n, k;
        cin >> n >> k;
        arr = vector<int>();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            arr.push_back(num);
            while (cnt < k)
            {

                cnt++;
            }
        }
    }
}