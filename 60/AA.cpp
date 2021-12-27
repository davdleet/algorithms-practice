#include <iostream>
#include <vector>

using namespace std;

int arr[10];
bool in_subset[10];

int tree(int treesize, int level)
{
    if (level > treesize)
    {
        int not_in = 0;
        int in = 0;
        for (int i = 0; i < treesize; i++)
        {
            if (in_subset[i])
            {
                in += arr[i];
            }
            else
            {
                not_in += arr[i];
            }
        }
        if (in == not_in)
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
        in_subset[level - 1] = true;
        int l = tree(treesize, level + 1);
        in_subset[level - 1] = false;
        int r = tree(treesize, level + 1);
        if (l == 1 || r == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    // freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int result = tree(N, 1);
    if (result == 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
