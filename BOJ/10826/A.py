import sys


sys.stdin = open("D:\Projects\AA\BOJ\\10826\input.txt")
input = sys.stdin.readline

N = int(input().rstrip())

arr = [0 for _ in range(10001)]

arr[1] = 1
arr[2] = 1
for i in range(3, N+1):
    arr[i] = arr[i-1] + arr[i-2]

print(arr[N])
