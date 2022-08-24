#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> a;
    a.push_back(0);
    vector<int> b = a;
    a.push_back(1);
    a[0] = 2;
    cout << a[0] << " " << b[0];
}