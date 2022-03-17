import sys

sys.stdin = open("D:\Projects\AA\BOJ\\17219\input.txt")
input = sys.stdin.readline

N, M = map(int, input().rstrip().split())
d = {}
for i in range(N):
    site, pw = input().rstrip().split()
    d[site] = pw
for i in range(M):
    query = input().rstrip()
    print(d[query])
