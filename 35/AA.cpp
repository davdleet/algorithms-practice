#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    vector<int> arr;
    vector<int> result;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    int idx = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            result.push_back(arr[i]);
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            result.push_back(arr[i]);
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << result[i] << " ";
    }
}