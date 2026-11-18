import sys
from collections import deque
sys.stdin = open("D:\Projects\AA\BOJ\\14503\input.txt")
input = sys.stdin.readline

N, M = map(int, input().rstrip().split())

r, c, d = map(int, input().rstrip().split())

arr = []
visited = [[0 for _ in range(M)] for __ in range(N)]
for i in range(N):
    line = list(map(int, input().rstrip().split()))
    arr.append(line)

dir = [(-1, 0), (0, 1), (1, 0), (0, -1)]

cnt = 0


def DFS(x, y, d):
    global cnt, visited, arr, dir
    next_d = d
    if not visited[x][y]:
        visited[x][y] = 1
        cnt += 1
    found = False
    for i in range(4):
        next_d = next_d - 1
        if next_d < 0:
            next_d = 3
        a = dir[next_d][0]
        b = dir[next_d][1]
        if x + a >= 0 and x + a < N and y+b >= 0 and y+b < M and arr[x+a][y+b] == 0 and not visited[x+a][y+b]:
            found = True
            DFS(x+a, y+b, next_d)
            break
    if not found:
        a = dir[d][0]
        b = dir[d][1]
        if x - a >= 0 and x - a < N and y-b >= 0 and y-b < M and arr[x-a][y-b] == 0:
            DFS(x-a, y-b, d)


DFS(r, c, d)
print(cnt)
