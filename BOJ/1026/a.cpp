#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A;
    vector<int> temp_A;
    vector<int> B;
    vector<pair<int, int>> sorted_B;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        A.push_back(temp);
        temp_A.push_back(temp);
    }
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        B.push_back(temp);
        sorted_B.push_back(pair<int, int>(temp, i));
    }
    sort(temp_A.begin(), temp_A.end());
    sort(sorted_B.begin(), sorted_B.end(), greater<pair<int, int>>());

    for (int i = 0; i < N; i++)
    {
        A[sorted_B[i].second] = temp_A[i];
    }
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        result += A[i] * B[i];
    }
    cout << result;
}