#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int arr[10000];
int top = -1;
int pop()
{
    return arr[top--];
}

void push(int num)
{
    arr[++top] = num;
}

int main()
{
    // freopen("input.txt", "rt", stdin);
    int N;
    int K;
    cin >> N >> K;
    int num = N;
    while (num > 0)
    {
        int div_result = num / K;
        push(num % K);
        num = num / K;
        if (num < K)
        {
            push(num);
            break;
        }
    }
    while (top != -1)
    {
        int num = pop();
        if (num >= 10)
        {
            cout << char('A' + num - 10);
        }
        else
        {
            cout << num;
        }
    }
}