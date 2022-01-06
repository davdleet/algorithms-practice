#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> Q;
    while (1)
    {
        int N;
        scanf("%d", &N);
        if (N == 0)
        {
            if (Q.empty())
            {
                cout << -1;
            }
            else
            {
                int temp = -Q.top();
                Q.pop();
                cout << temp;
            }
        }
        else if (N == -1)
        {
            break;
        }
        else
        {
            Q.push(-N);
        }
    }
}