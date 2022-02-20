import sys
from bisect import bisect_left

sys.stdin = open("D:\Projects\AA\BOJ\\16564\input.txt")
input = sys.stdin.readline

N, K = map(int, input().split())
arr = []
for i in range(N):
    t = int(input().rstrip())
    arr.append(t)
arr.sort()

print(arr)
