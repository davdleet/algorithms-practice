#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    int N;
    scanf("%d", &N);
    vector<int> skill_arr;
    for (int i = 0; i < N; i++)
    {
        int current;
        scanf("%d", &current);
        skill_arr.push_back(current);
    }
    for (int i = 0; i < skill_arr.size(); i++)
    {
        int current = skill_arr[i];
        int rank = 1;
        for (int j = 0; j < i; j++)
        {
            if (skill_arr[j] >= current)
            {
                rank++;
            }
        }
        cout << rank << " ";
    }
}