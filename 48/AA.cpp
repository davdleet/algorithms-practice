#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    vector<vector<int>> arr;
    //freopen("input.txt", "rt", stdin);
    for (int i = 0; i < 9; i++)
    {
        vector<int> temp;
        arr.push_back(temp);
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int num;
            cin >> num;
            arr[i].push_back(num);
        }
    }
    for (int i = 0; i < 9; i++)
    {
        double total = 0;
        double average = 0;
        for (int j = 0; j < 9; j++)
        {
            double current = arr[i][j];
            total += current;
        }
        average = total / 9;
        average = round(average);
        int smallest_diff = abs(arr[i][0] - average);
        int closest = arr[i][0];
        for (int j = 1; j < 9; j++)
        {
            int current = arr[i][j];
            int diff = abs(current - average);
            if (diff < smallest_diff)
            {
                smallest_diff = diff;
                closest = arr[i][j];
            }
            else if (smallest_diff == diff)
            {
                if (current > closest)
                {
                    smallest_diff = diff;
                    closest = current;
                }
            }
        }
        cout << average << " " << closest << endl;
    }
}