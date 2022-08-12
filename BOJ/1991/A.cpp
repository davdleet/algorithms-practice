#include <iostream>
#include <vector>
using namespace std;

pair<int, int> temp({-1, -1});
vector<pair<int, int>> arr(26, temp);

void preorder(int current)
{
    cout << char(current + 'A');
    if (arr[current].first != -1)
    {
        preorder(arr[current].first);
    }
    if (arr[current].second != -1)
    {
        preorder(arr[current].second);
    }
}

void inorder(int current)
{
    if (arr[current].first != -1)
    {
        inorder(arr[current].first);
    }
    cout << char(current + 'A');
    if (arr[current].second != -1)
    {
        inorder(arr[current].second);
    }
}

void postorder(int current)
{
    if (arr[current].first != -1)
    {
        postorder(arr[current].first);
    }
    if (arr[current].second != -1)
    {
        postorder(arr[current].second);
    }
    cout << char(current + 'A');
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char a, b, c;
        cin >> a >> b >> c;
        int a_i, b_i, c_i;
        a_i = a - 'A';
        b_i = b - 'A';
        c_i = c - 'A';
        if (b == '.')
        {
            b_i = -1;
        }
        if (c == '.')
        {
            c_i = -1;
        }
        arr[a_i].first = b_i;
        arr[a_i].second = c_i;
    }
    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
}