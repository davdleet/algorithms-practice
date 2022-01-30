import sys

sys.stdin = open("D:\Projects\AA\BOJ\\11049\input.txt", "r")
input = sys.stdin.readline

n = int(sys.stdin.readline())
dp = [[-1 for _ in range(505)] for _ in range(505)]
a = []
b = []


def solve(start, end):
    if dp[start][end] != -1:
        return dp[start][end]
    if start == end:
        dp[start][end] = 0
        return dp[start][end]
    dp[start][end] = 987654321
    for i in range(start, end):
        dp[start][end] = min(dp[start][end], a[start] * b[i]
                             * b[end] + solve(start, i) + solve(i+1, end))
    return dp[start][end]


for i in range(n):
    temp_a, temp_b = map(int, input().rstrip().split())
    a.append(temp_a)
    b.append(temp_b)

print(solve(0, n-1))
