import sys

sys.stdin = open("D:\Projects\AA\BOJ\contest\\777\9\input.txt")
input = sys.stdin.readline

K = int(input().rstrip())

A = 1
B = 2
C = (2 ** K)-1

cnt = 0
for i in range(3, C+1):
    for j in range(2, i):
        for k in range(1, j):
            None

print(cnt % 1000003)
