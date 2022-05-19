import sys

sys.stdin = open("D:\Projects\AA\BOJ\\6064\input.txt")
input = sys.stdin.readline


T = int(input().rstrip())
print(T)

for i in range(T):
    M, N, X, Y = map(int, input().rstrip().split())
    found = False
    num = 0
    x = 0
    y = 0
    while not found:
        x = num +
