#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 0; i < N; i++)
    {
        string s;
        getline(cin, s);
        bool arr[26];
        fill(arr, arr + 26, false);
        for (int j = 0; j < s.size(); j++)
        {
            int idx = int((tolower(s[j])) - 'a');
            if (idx > -1 && idx < 26)
            {
                arr[idx] = true;
            }
        }
        bool pangram = true;
        for (int j = 0; j < 26; j++)
        {
            if (!arr[j])
            {
                pangram = false;
                break;
            }
        }
        if (pangram)
        {
            cout << "pangram" << endl;
        }
        else
        {
            cout << "missing ";
            for (int j = 0; j < 26; j++)
            {
                if (!arr[j])
                {
                    cout << char('a' + j);
                }
            }
            cout << endl;
        }
    }
}