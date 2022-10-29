import sys

sys.stdin = open("D:\Projects\AA\BOJ\\2294\input.txt")
input = sys.stdin.readline

n, k = map(int, input().rstrip().split())

coins = []
for i in range(n):
    temp = int(input().rstrip())
    coins.append(temp)

dp = [100000000000 for _ in range(100001)]

for i in range(len(coins)):
    coin = coins[i]
    dp[coin] = 1

for i in range(1, k+1):
    for j in range(1, i):
        dp[i] = min(dp[i], dp[j] + dp[i-j])

if dp[k] == 100000000000:
    print(-1)
else:
    print(dp[k])
