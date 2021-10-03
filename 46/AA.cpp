#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    int N, K;
    cin >> N;
    vector<int> arr;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    cin >> K;
    int count = 0;
    int pos = 0;
    int next = 0;
    int result = 0;
    while (count < K + 1)
    {
        int initial = pos;
        if (arr[pos] > 0)
        {
            arr[pos]--;
        }
        else
        {
            bool found = false;
            while (!found)
            {
                if (arr[pos] > 0)
                {
                    break;
                }
                pos++;
                if (pos > arr.size())
                {
                    pos = 0;
                }
                else if (pos == initial)
                {
                    cout << -1;
                    return 0;
                }
            }
            arr[pos]--;
        }
        if (pos + 1 > arr.size())
        {
            pos = 0;
        }
        else
        {
            pos++;
        }
        count++;
    }
    cout << pos;
}