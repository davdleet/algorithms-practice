import sys

sys.stdin = open("D:\Projects\AA\study-book\\220\input.txt")
input = sys.stdin.readline

N = int(input().rstrip())

arr = list(map(int, input().rstrip().split()))

d = [0] * 100

d[0] = arr[0]
d[1] = max(arr[0], arr[1])

for i in range(2, N):
    d[i] = max(d[i-1], d[i-2] + arr[i])
print(d[N-1])
