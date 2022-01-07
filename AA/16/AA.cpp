#include <iostream>

using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    int arr1[128] = {0};
    int arr2[128] = {0};
    char input1[101];
    char input2[101];
    bool yes = true;
    scanf("%s", input1);
    scanf("%s", input2);
    for (int i = 0; input1[i] != '\0'; i++)
    {
        char current = input1[i];
        int index = (int)current;
        arr1[index]++;
    }
    for (int i = 0; input2[i] != '\0'; i++)
    {
        char current = input2[i];
        int index = (int)current;
        arr2[index]++;
    }
    for (int i = 0; i < 128; i++)
    {
        if (arr1[i] != arr2[i])
        {
            yes = false;
            break;
        }
    }
    if (yes)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}