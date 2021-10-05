#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    vector<vector<int>> arr;
    for (int i = 0; i < N + 2; i++)
    {
        vector<int> inner;
        arr.push_back(inner);
    }
    for (int i = 0; i < N + 2; i++)
    {
        if (i == 0 || i == N + 1)
        {
            for (int j = 0; j < N + 2; j++)
            {
                arr[i].push_back(0);
            }
        }
        else
        {

            for (int j = 0; j < N + 2; j++)
            {
                if (j == 0 || j == N + 1)
                {
                    arr[i].push_back(0);
                }
                else
                {
                    int num;
                    cin >> num;
                    arr[i].push_back(num);
                }
            }
        }
    }
    int count = 0;
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            int current = arr[i][j];
            int top = arr[i - 1][j];
            int bottom = arr[i + 1][j];
            int left = arr[i][j - 1];
            int right = arr[i][j + 1];
            if (current > top && current > bottom && current > left && current > right)
            {
                count++;
            }
        }
    }
    cout << count;
    /*
    for (int i = 0; i < N + 2; i++)
    {
        for (int j = 0; j < N + 2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }*/
}