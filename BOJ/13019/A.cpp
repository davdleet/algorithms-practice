#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    string A, B;
    cin >> A >> B;
    string temp_A, temp_B;
    temp_A = A;
    temp_B = B;
    sort(temp_A.begin(), temp_A.end());
    sort(temp_B.begin(), temp_B.end());
    if (temp_A != temp_B)
    {
        cout << -1;
        return 0;
    }
    int cnt = 0;
    int j = B.size() - 1;
    for (int i = A.size() - 1; i > -1; i--)
    {
        if (A[i] != B[j])
        {
            cnt++;
        }
        else
        {
            j--;
        }
    }
    cout << cnt;
}