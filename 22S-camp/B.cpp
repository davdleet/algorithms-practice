#include <iostream>

using namespace std;

int main()
{
    freopen("B.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int used = 0;
    int N;
    int previous_phone = -1;
    int previous_used = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int phone;
        int current_use;
        cin >> phone;
        if (phone == previous_phone)
        {
            current_use = previous_used * 2;
        }
        else
        {
            current_use = 2;
        }
        previous_phone = phone;
        previous_used = current_use;
        used += current_use;
        if (used >= 100)
        {
            used = 0;
            previous_phone = -1;
            previous_used = 0;
        }
    }
    cout << used;
}