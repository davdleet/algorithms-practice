#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    long long int A, B, C;
    cin >> A >> B >> C;
    long long int ans = 1;
    // use B as a counter for when to multiply
    while (B)
    {
        // when B is odd, multiply all previous multiplications with current A
        if (B % 2)
        {
            ans = (ans * A) % C;
        }
        // square multiply A every iteration
        A = (A * A) % C;
        // divide B by two every iteration (divide and conquer)
        B >>= 1;
    }
    cout << ans;
}