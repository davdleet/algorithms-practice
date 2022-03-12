import sys
from collections import deque
sys.stdin = open("D:\Projects\AA\BOJ\\1260\input.txt")
input = sys.stdin.readline

N, M, V = map(int, input().rstrip().split())


arr = [[] for _ in range(N+1)]
visited = []
for i in range(M):
    a, b = map(int, input().rstrip().split())
    arr[a].append(b)
    arr[b].append(a)

for i in range(len(arr)):
    arr[i].sort()


def DFS(num):
    visited.append(num)
    print(num, end=' ')
    for i in range(len(arr[num])):
        if arr[num][i] in visited:
            continue
        DFS(arr[num][i])


def BFS(num):
    visited.append(num)
    q = deque([num])
    while q:
        c = q.popleft()
        print(c, end=' ')
        for i in range(len(arr[c])):
            if arr[c][i] not in visited:
                q.append(arr[c][i])
                visited.append(arr[c][i])


DFS(V)
print()
visited = []
BFS(V)
print()
