#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    int cnt = 0;
    int num = N;

    if (num % 5 == 0)
    {
        cout << num / 5;
        return 0;
    }
    int temp = num;
    int temp_cnt = 0;
    while (temp > 0)
    {
        temp = temp - 3;
        temp_cnt++;

        if (temp % 5 == 0)
        {
            cnt = temp / 5;
            break;
        }
    }
    if (temp < 0)
    {
        cout << -1;
        return 0;
    }
    cnt += temp_cnt;
    cout << cnt;
}