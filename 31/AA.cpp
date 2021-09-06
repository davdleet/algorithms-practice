#include <iostream>
#include <string>
using namespace std;

int main()
{
    //freopen("input.txt", "rt", stdin);
    string input;
    cin >> input;
    //cout << input;
    int h_index = -1;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == 'H')
        {
            h_index = i;
        }
    }
    string c_string = input.substr(1, h_index - 1);
    int c_mass, h_mass;
    if (c_string != "")
    {
        c_mass = stoi(c_string);
    }
    else
    {
        c_mass = 1;
    }
    string h_string = input.substr(h_index + 1);
    if (h_string != "")
    {
        h_mass = stoi(h_string);
    }
    else
    {
        h_mass = 1;
    }
    int result = 12 * c_mass + 1 * h_mass;
    cout << result;
}