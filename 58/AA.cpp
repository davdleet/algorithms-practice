#include <iostream>

using namespace std;

int tree(int n)
{
    if (n > 7)
    {
        return 0;
    }
    else
    {
        // preorder traversal
        // cout << n << " ";
        tree(n * 2);
        // inorder traversal
        // cout << n << " ";
        tree(n * 2 + 1);
        // postorder traversal
        cout << n << " ";
    }
}

int main()
{
    tree(1);
}