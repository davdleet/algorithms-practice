#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    int value;
    node *left = nullptr;
    node *right = nullptr;
    node(int val)
    {
        value = val;
    }
    void insert(node *n)
    {
        if (n->value < value)
        {
            if (left)
            {
                left->insert(n);
            }
            else
            {
                left = n;
            }
        }
        else
        {
            if (right)
            {
                right->insert(n);
            }
            else
            {
                right = n;
            }
        }
    }
};

void postorder(node *n)
{
    if (n->left)
    {
        postorder(n->left);
    }
    if (n->right)
    {
        postorder(n->right);
    }
    cout << n->value << "\n";
}

int main()
{
    freopen("input.txt", "rt", stdin);
    string input;
    cin >> input;
    int num = stoi(input);
    node *first = new node(num);
    while (true)
    {
        input = "";
        cin >> input;
        if (input == "")
        {
            break;
        }
        num = stoi(input);
        node *new_node = new node(num);
        first->insert(new_node);
    }
    postorder(first);
}