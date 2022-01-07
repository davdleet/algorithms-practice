#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    vector<int> arr;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    bool done = false;
    while (!done)
    {
        bool swapped = false;
        for (int i = 0; i < N - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
        {
            done = true;
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
}