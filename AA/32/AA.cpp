#include <iostream>
#include <vector>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    vector<int> arr;
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    int idx = 0;
    for (int i = 0; i < N; i++)
    {
        int smallest = arr[i];
        int small_idx = i;
        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] < smallest)
            {
                smallest = arr[j];
                small_idx = j;
            }
        }
        if (i != small_idx)
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[small_idx];
            arr[small_idx] = temp;
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
}