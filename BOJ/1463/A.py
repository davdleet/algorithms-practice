import sys

sys.stdin = open("D:\Projects\AA\BOJ\\1463\input.txt")
input = sys.stdin.readline

N = int(input().rstrip())

arr = [0 for _ in range(1000001)]

for i in range(2, N+1):
    arr[i] = arr[i-1] + 1
    if i % 2 == 0:
        arr[i] = min(arr[i], arr[i//2]+1)
    if i % 3 == 0:
        arr[i] = min(arr[i], arr[i//3]+1)

print(arr[N])
