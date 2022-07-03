#include <iostream>
#include <map>
#include <vector>

#define MAX_N 51
using namespace std;
int N, M;
int T;
vector<int> parent(MAX_N, 1);

int find(int num)
{
    int n = num;
    while (n != parent[n])
    {
        n = parent[n];
    }
    return n;
}

void solve()
{
}

int main()
{
    freopen("input.txt", "rt", stdin);
    cin >> N >> M;
    cin >> T;
    for (int i = 1; i < N; i++)
    {
        parent[i] = i;
    }
}