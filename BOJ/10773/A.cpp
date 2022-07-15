#include <iostream>
#include <stack>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    int K;
    cin >> K;
    stack<int> st;
    for (int i = 0; i < K; i++)
    {
        int num;
        cin >> num;
        if (!num)
        {
            st.pop();
        }
        else
        {
            st.push(num);
        }
    }
    int total = 0;
    while (st.size())
    {
        total += st.top();
        st.pop();
    }
    cout << total;
}