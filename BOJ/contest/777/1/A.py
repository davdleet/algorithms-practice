import sys

sys.stdin = open("D:\Projects\AA\BOJ\contest\\777\\1\input.txt")
input = sys.stdin.readline
N = int(input().rstrip())

ans = 1
for i in range(N):
    ans = ans * 2

print(ans)
