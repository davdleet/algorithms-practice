#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string input;
    getline(cin, input);
    for (int i = 0; i < input.size(); i++)
    {
        if (input.at(i) != 32)
        {
            cout << (char)tolower(input.at(i));
        }
    }
}