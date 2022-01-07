#include <iostream>

using namespace std;

int arr[10];
int treesize;
int sum = 0;
int target;

int tree(int level, int num)
{
    if (level > treesize)
    {
        if (num == target)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        int l_add = tree(level + 1, num + arr[level - 1]);
        int l_sub = tree(level + 1, num - arr[level - 1]);
        int r = tree(level + 1, num);
        return (l_add + l_sub + r);
    }
}

int main()
{
    // freopen("input.txt", "rt", stdin);
    int N, M;
    cin >> N >> M;
    treesize = N;
    target = M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int count = tree(1, 0);
    if (count == 0)
    {
        count = -1;
    }
    cout << count;
}