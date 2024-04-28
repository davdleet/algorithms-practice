#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> matrix;

matrix identity(int size)
{
    matrix m(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++)
    {
        m[i][i] = 1;
    }
    return m;
}

matrix multiply(matrix A, matrix B, long long mod)
{
    matrix result = matrix(A.size(), vector<int>(A[0].size(), 0));
    for (int i = 0; i < A.size(); i++)
    {
        // for each number in resulting matrix
        for (int j = 0; j < A.size(); j++)
        {
            for (int k = 0; k < A.size(); k++)
            {
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }

    return result;
}

matrix exponent(matrix A, long long B, long long mod)
{

    matrix result = matrix(A.size(), vector<int>(A[0].size(), 0));
    if (B == 0)
    {
        return identity(A.size());
    }
    result = exponent(A, B / 2, mod);
    result = multiply(result, result, mod);

    if (B % 2 == 1)
    {
        result = multiply(result, A, mod);
    }
    return result;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long N, B;
    cin >> N >> B;
    matrix A = vector<vector<int>>(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;
            A[i][j] = n;
        }
    }
    matrix result = exponent(A, B, 1000);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result.size(); j++)
        {
            cout << result[i][j];
            if (j != result.size() - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}