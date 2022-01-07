#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    vector<int> arr;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    vector<int> result;
    for (int i = 0; i < N; i++)
    {
        result.push_back(0);
    }
    result[N - 1] = N;
    int val = N - 1;
    for (int i = N - 2; i >= 0; i--)
    {
        int num = arr[i];
        int pos = i;
        for (int j = 0; j < num; j++)
        {
            result[pos] = result[pos + 1];
            pos++;
        }
        result[pos] = val;
        val--;
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}