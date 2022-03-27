import sys

sys.stdin = open('D:\Projects\AA\BOJ\\2579\input.txt')
input = sys.stdin.readline

N = int(input().rstrip())

arr = []
for i in range(N):
    num = int(input().rstrip())
    arr.append(num)

ans = 0
dp = [0 for _ in range(N)]

dp[0] = arr[0]

if N < 2:
    print(dp[0])
    sys.exit(0)

dp[1] = max(arr[1], arr[1] + arr[0])

if N < 3:
    print(dp[N-1])
    sys.exit(0)

dp[2] = max(dp[0] + arr[2], arr[1] + arr[2])


for i in range(3, N):
    dp[i] = max(arr[i-1] + dp[i-3] + arr[i], dp[i-2] + arr[i])
print(dp[N-1])
