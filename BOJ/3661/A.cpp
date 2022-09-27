#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        vector<pair<int, int>> arr;
        vector<int> max_pay;
        int p, n;
        cin >> p >> n;
        vector<int> paid = vector<int>(n, 0);
        for (int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            arr.push_back({num, j});
            max_pay.push_back(num);
        }
        sort(arr.begin(), arr.end());
        int remaining = p;
        int first_to_pay = 0;
        while (remaining > 0)
        {
            int divided = remaining / (n - first_to_pay);
            remaining = remaining % (n - first_to_pay);
            for (int j = first_to_pay; j < n; j++)
            {
                if (arr[j].first <= divided)
                {
                    first_to_pay++;
                    paid[arr[j].second] = max_pay[arr[j].second];
                    remaining -= max_pay[arr[j].second];
                }
                else
                {
                    remaining -= divided;
                }
            }
        }
        for (int j = 0; j < paid.size(); j++)
        {
            cout << paid[j] << " ";
        }
        cout << endl;
        cout << remaining << endl;
    }
}