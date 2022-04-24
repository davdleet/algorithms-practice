import sys

sys.stdin = open("D:\Projects\AA\BOJ\\11659\input.txt")
input = sys.stdin.readline

N, M = map(int, input().rstrip().split())

arr = [0]
arr = arr + list(map(int, input().rstrip().split()))
sum = [0] * (N+1)

sum[0] = 0
for i in range(1, len(arr)):
    sum[i] = arr[i] + sum[i-1]

for i in range(M):
    s, e = map(int, input().rstrip().split())
    s = s - 1
    print(sum[e] - sum[s])
