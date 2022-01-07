#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    int N;
    int solutions = 0;
    cin >> N;
    for (int i = 2; i < N; i++)
    {

        vector<int> arr1;
        int idx_sum = 0;
        for (int j = 1; j < i + 1; j++)
        {
            arr1.push_back(j);
            idx_sum += j;
        }
        int remaining = N - idx_sum;
        if (remaining < 0)
        {
            continue;
        }
        if (remaining % i == 0)
        {
            int divided = remaining / i;
            int result = 0;
            for (int j = 0; j < arr1.size(); j++)
            {
                arr1[j] += divided;
                result += arr1[j];
            }
            if (result == N)
            {
                solutions++;
                for (int j = 0; j < arr1.size(); j++)
                {
                    if (j != arr1.size() - 1)
                    {
                        cout << arr1[j] << " + ";
                    }
                    else
                    {
                        cout << arr1[j] << " = " << result << endl;
                    }
                }
            }
        }
    }
    cout << solutions;
}