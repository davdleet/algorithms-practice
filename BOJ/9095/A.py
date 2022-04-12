import sys

sys.stdin = open("D:\Projects\AA\BOJ\9095\input.txt")
input = sys.stdin.readline

T = int(input().rstrip())

arr = [0, 1, 2, 4]
dp = [0, 1, 2, 4]

sum = 7
for i in range(4, 12):
    dp.append(dp[i-1] + dp[i-2] + dp[i-3])

for i in range(T):
    num = int(input().rstrip())
    print(dp[num])
