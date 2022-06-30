import sys

sys.stdin = open("D:\Projects\AA\BOJ\\1149\input.txt")
input = sys.stdin.readline

N = int(input().rstrip())

arr = [[0 for _ in range(3)] for __ in range(N)]

for i in range(N):
    R, G, B = map(int, input().rstrip().split())
    arr[i][0] = R
    arr[i][1] = G
    arr[i][2] = B


dp = []
