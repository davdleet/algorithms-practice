import sys
from bisect import bisect_left

sys.stdin = open("D:\Projects\AA\BOJ\\16564\input.txt")
input = sys.stdin.readline

N, K = map(int, input().split())
arr = []
for i in range(N):
    t = int(input().rstrip())
    arr.append(t)

hi = 1000000000
lo = 0


while lo + 1 < hi:
    mid = (hi + lo) // 2
    temp = 0
    for i in range(N):
        temp += max(mid - arr[i], 0)
    if K < temp:
        hi = mid
    else:
        lo = mid
print(lo)
