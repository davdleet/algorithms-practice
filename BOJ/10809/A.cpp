#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);
    string s;
    cin >> s;
    vector<int> alphabet(26, -1);
    for (int i = 0; i < s.size(); i++)
    {
        int current = int(s[i]) - 'a';
        if (alphabet[current] == -1)
        {
            alphabet[current] = i;
        }
    }
    for (int i = 0; i < alphabet.size(); i++)
    {
        cout << alphabet[i] << " ";
    }
}