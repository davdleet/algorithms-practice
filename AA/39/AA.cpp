#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    int N;
    int M;
    vector<int> arr1, arr2;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr1.push_back(num);
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        arr2.push_back(num);
    }
    vector<int> result;
    for (int i = 0; i < N + M; i++)
    {
        result.push_back(0);
    }
    int pos1 = 0;
    int pos2 = 0;
    int pos3;
    for (int i = 0; i < N + M; i++)
    {
        if (pos1 >= arr1.size())
        {
            for (int j = i; j < N + M; j++)
            {
                result[j] = arr2[pos2];
                pos2++;
            }
            break;
        }
        else if (pos2 >= arr2.size())
        {
            for (int j = i; j < N + M; j++)
            {
                result[j] = arr1[pos1];
                pos1++;
            }
            break;
        }
        else
        {
            if (arr1[pos1] <= arr2[pos2])
            {
                result[i] = arr1[pos1];
                pos1++;
            }
            else
            {
                result[i] = arr2[pos2];
                pos2++;
            }
        }
    }
    for (int i = 0; i < N + M; i++)
    {
        cout << result[i] << " ";
    }
}