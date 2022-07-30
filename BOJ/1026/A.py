import sys

sys.stdin = open("D:\Projects\AA\BOJ\\1026\input.txt")
input = sys.stdin.readline


N = int(input().rstrip())

A = list(map(int, input().rstrip().split()))
B = list(map(int, input().rstrip().split()))
ans = 0

while(len(A)):
    ans += A.pop(A.index(max(A))) * B.pop(B.index(min(B)))

print(ans)
