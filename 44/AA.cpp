#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool bigger(int a, int b)
{
    return a < b;
};

int main()
{
    //freopen("input.txt", "rt", stdin);
    int N, C;
    cin >> N;
    cin >> C;
    vector<int> arr;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end(), bigger);
    int right = arr[arr.size() - 1];
    int left = arr[0];
    int answer;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        int prev = arr[0];
        int horse_count = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            int current = arr[i];
            if ((current - prev) >= middle)
            {
                prev = arr[i];
                horse_count++;
            }
        }
        if (horse_count >= C)
        {
            answer = middle;
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    cout << answer;
}