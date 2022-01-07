#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    //freopen("input1.txt", "rt", stdin);
    int N, M;
    cin >> N;
    vector<int> arr1, arr2;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr1.push_back(num);
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        arr2.push_back(num);
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    int pos1 = 0, pos2 = 0;
    vector<int> result;

    while (pos1 <= N - 1 && pos2 <= M - 1)
    {
        int val1 = arr1[pos1];
        int val2 = arr2[pos2];
        if (val1 < val2)
        {
            pos1++;
        }
        else if (val2 < val1)
        {
            pos2++;
        }
        else
        {
            result.push_back(val1);
            pos1++;
            pos2++;
        }
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}