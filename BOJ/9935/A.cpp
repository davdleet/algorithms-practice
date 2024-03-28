#include <iostream>
#include <deque>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    string result;
    for (char ch : a)
    {
        result.push_back(ch);
        if (result.size() >= b.size() && result.substr(result.size() - b.size()) == b)
        {
            result.erase(result.size() - b.size());
        }
    }
    if (result.empty())
    {
        cout << "FRULA";
    }
    else
    {
        cout << result;
    }
}