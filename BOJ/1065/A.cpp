#include <iostream>
#include <vector>

using namespace std;

bool check(int num)
{
    vector<int> arr;
    int temp = num;
    if (num < 100)
    {
        return true;
    }
    while (temp / 10 != 0)
    {
        arr.push_back(temp % 10);
        temp = temp / 10;
    }
    arr.push_back(temp);
    int diff1 = arr[0] - arr[1];
    for (int i = 1; i < arr.size(); i++)
    {
        if ((arr[i - 1] - arr[i]) != diff1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        if (check(i))
        {
            count++;
        }
    }
    cout << count;
}