#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    stack<char> s;
    // freopen("input.txt", "rt", stdin);
    char str[31];
    scanf("%s", str);
    char current_char = ' ';
    int i = 0;
    while (current_char != '\0')
    {
        current_char = str[i++];

        if (current_char == '(')
        {
            s.push('(');
        }
        else if (current_char == ')')
        {
            if (s.size() == 0)
            {
                cout << "NO";
                return 0;
            }
            s.pop();
        }
    }
    if (s.size() == 0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}