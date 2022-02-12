import sys

sys.stdin = open('D:\Projects\AA\BOJ\\2370\input.txt', 'r')
input = sys.stdin.readline

N = int(input().rstrip())

lines = []
wall = []
posters = []

for i in range(N):
    l, r = map(int, input().rstrip().rsplit())

    lines.append(l)

    lines.append(r)
