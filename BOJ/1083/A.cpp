#include <iostream>
#include <vector>
using namespace std;

vector<int> arr(51, 0);

int main()
{
    freopen("/Users/sungwonlee/Documents/Projects/algorithms-practice/BOJ/1083/input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    int S;
    cin >> S;
    bool end = false;
    int left = S;
    int current_idx = 0;
    while (left > 0)
    {
        if (current_idx >= N)
        {
            break;
        }
        int max_val = -1;
        int max_idx;
        int last_idx = current_idx + left;
        if (last_idx > N)
        {
            last_idx = N;
        }
        for (int i = current_idx; i < last_idx + 1; i++)
        {
            if (arr[i] > max_val)
            {
                max_val = arr[i];
                max_idx = i;
            }
        }

        for (int i = max_idx; i > current_idx; i--)
        {
            int t;
            t = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = t;
            left--;
        }
        current_idx++;
    }
    // print answer
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
}