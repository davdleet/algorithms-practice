#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> cnts(1001, 1);
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    int ans = 1;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && cnts[j] >= cnts[i])
            {

                cnts[i] = cnts[j] + 1;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        int current = cnts[i];
        if (current > ans)
        {
            ans = current;
        }
    }
    cout << ans;
}
