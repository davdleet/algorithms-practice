#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    vector<vector<int>> blocks;
    for (int i = 0; i < N; i++)
    {
        vector<int> temp;
        for (int j = 0; j < N; j++)
        {
            temp.push_back(0);
        }
        blocks.push_back(temp);
    }
    for (int i = 0; i < N; i++)
    {
        int front_max;
        cin >> front_max;
        for (int j = 0; j < blocks.size(); j++)
        {
            blocks[j][i] = front_max;
        }
    }
    for (int i = N - 1; i > -1; i--)
    {
        int rear_max;
        cin >> rear_max;
        for (int j = N - 1; j > -1; j--)
        {
            if (rear_max < blocks[i][j])
            {
                blocks[i][j] = rear_max;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            result += blocks[i][j];
        }
    }
    cout << result;
}