import sys

sys.stdin = open("D:\Projects\AA\BOJ\\11727\input.txt")
input = sys.stdin.readline

N = int(input().rstrip())
dp = [0] * (N+1)

dp[1] = 1

if N == 1:
    print(dp[1])
    sys.exit(0)

dp[2] = 3
for i in range(3, len(dp)):
    dp[i] = dp[i-1] + dp[i-2] * 2

print(dp[N] % 10007)
