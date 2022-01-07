#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    int N, M;
    cin >> N >> M;
    vector<int> arr;
    int right = 0;
    int left = 1;
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        right += num;
        arr.push_back(num);
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int middle = (right + left) / 2;
    int answer;
    while (right >= left)
    {
        int count = 0;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int current = arr[i];
            sum += current;
            //container overflow
            if (sum > middle)
            {
                count++;
                sum = 0;
                sum += current;
            }
            //container full
            else if (sum == middle)
            {
                count++;
                sum = 0;
            }
        }

        if (sum > 0)
        {
            count++;
        }
        //if middle value is big enough
        if (middle >= max && count <= M)
        {
            answer = middle;
            right = middle - 1;
            middle = (left + right) / 2;
        }
        //current middle is too small
        else
        {
            left = middle + 1;
            middle = (left + right) / 2;
        }
    }
    cout << answer;
}