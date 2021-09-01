#include <iostream>
#include <vector>
using namespace std;

int digit_sum(int x)
{
    int num = 0;
    int tmp;
    while (x > 10)
    {
        tmp = (x % 10);
        num += tmp;
        x /= 10;
    }
    num += (x % 10);
    //cout << "num: " << num << endl;
    return num;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    int N;
    scanf("%d", &N);
    vector<int> result;
    int max = 0;
    int max_og = 0;
    for (int i = 0; i < N; i++)
    {
        int temp = 0;
        scanf("%d", &temp);
        int num = digit_sum(temp);
        if (num > max)
        {
            max = num;
            max_og = temp;
        }
        else if (num == max)
        {
            if (temp > max_og)
            {
                max_og = temp;
            }
        }
    }
    cout << max_og;
}