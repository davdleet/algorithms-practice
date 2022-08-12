#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;
deque<int> result;
deque<int> ins;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    // back of deque == 위 front of deque == 아래
    // 되돌리기 전 --> 아래 5 4 3 2 1 위
    for (int i = 0; i < N; i++)
    {
        dq.push_back(N - i);
    }
    for (int i = 0; i < N; i++)
    {
        int action;
        cin >> action;
        ins.push_back(action);
    }
    for (int i = N - 1; i > -1; i--)
    {
        int action = ins[i];
        int num;
        switch (action)
        {
        // take card from back of dq to back of result
        case 1:
            num = dq.back();
            result.push_back(num);
            dq.pop_back();
            break;
        // take card from back of dq to back - 1 of result
        case 2:
            num = dq.back();
            result.insert(result.end() - 1, num);
            dq.pop_back();
            break;
        // take card from back of dq to front of result
        case 3:
            num = dq.back();
            result.push_front(num);
            dq.pop_back();
            break;
        default:
            break;
        }
    }
    for (int i = N - 1; i > -1; i--)
    {
        cout << result[i] << " ";
    }
}