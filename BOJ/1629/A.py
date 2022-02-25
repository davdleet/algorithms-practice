import sys
sys.stdin = open("D:\Projects\AA\BOJ\\1629\input.txt")
input = sys.stdin.readline

A, B, C = map(int, input().rstrip().split())
ans = 1
while B:
    if B % 2:
        ans = (ans * A) % C
    A = (A * A) % C
    B >>= 1
print(ans)
