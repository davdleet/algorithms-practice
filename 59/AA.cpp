#include <iostream>
#include <vector>
using namespace std;

vector<bool> arr;

int tree(int treesize, int num)
{
    if (num > treesize)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i])
            {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
        return 0;
    }
    else
    {
        arr[num - 1] = true;
        tree(treesize, num + 1);
        arr[num - 1] = false;
        tree(treesize, num + 1);
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        arr.push_back(false);
    }
    tree(N, 1);
    /*
    for (int i = 1; i <= N; i++)
    {
        int children_count = N - i;
        if (children_count >= 2)
        {
            for (int j = i; j <= N; j++)
            {
                cout << j << " ";
            }
        }
        cout << endl;
        int child = i + 1;
        for (int j = 0; j < children_count; j++)
        {
            cout << i << " " << child << endl;
            child++;
        }
        cout << i;
    }
    */
}