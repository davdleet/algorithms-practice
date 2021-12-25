#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    // freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    stack<int> s;
    vector<char> str;
    int target = 1;
    int bottom = 1;
    int last_popped = -1;
    int read = 0;
    while (target <= N)
    {
        int num = 0;
        if (read < N)
        {
            cin >> num;
            s.push(num);
            str.push_back('P');
            read++;
        }
        else
        {
            num = s.top();
        }
        if (num == target)
        {
            int top = s.top();
            while (top == target && !s.empty())
            {
                s.pop();
                str.push_back('O');
                target++;
                if (s.empty())
                {
                    break;
                }
                top = s.top();
            }
        }
        else
        {
            if (read < N)
            {
                // cout << "test";
            }
            else
            {
                cout << "impossible";
                return 0;
            }
        }
    }
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i];
    }
}