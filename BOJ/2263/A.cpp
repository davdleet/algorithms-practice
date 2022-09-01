#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> inorder;
vector<int> postorder;

// separate indices for inorder and postorder
void preorder(int i_s, int i_e, int p_s, int p_e)
{
    if (i_s > i_e)
    {
        return;
    }
    int root = postorder[p_e];
    // index of root in inorder
    int root_idx = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    cout << root << " ";
    if (i_s == i_e)
    {
        return;
    }
    // total length of partition
    int total_len = i_e - i_s;
    int left_len = root_idx - i_s;
    int right_len = i_e - root_idx;
    // first half
    int next_i_s_1 = i_s;
    int next_i_e_1 = i_s + left_len - 1;
    int next_p_s_1 = p_s;
    int next_p_e_1 = p_s + left_len - 1;
    preorder(next_i_s_1, next_i_e_1, next_p_s_1, next_p_e_1);

    // second half
    int next_i_s_2 = root_idx + 1;
    int next_i_e_2 = i_e;
    int next_p_s_2 = next_p_e_1 + 1;
    int next_p_e_2 = next_p_s_2 + right_len - 1;
    preorder(next_i_s_2, next_i_e_2, next_p_s_2, next_p_e_2);
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        inorder.push_back(n);
    }
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        postorder.push_back(n);
    }
    preorder(0, postorder.size() - 1, 0, postorder.size() - 1);
}