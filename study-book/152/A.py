import sys
from collections import deque
sys.stdin = open("D:\Projects\AA\study-book\\152\input.txt")
input = sys.stdin.readline

N, M = map(int, input().rstrip().split())

arr = []
check = [[0 for _ in range(M)] for __ in range(N)]

for i in range(N):
    line = list(map(int, list(input().rstrip())))
    arr.append(line)

dir = [(1, 0), (-1, 0), (0, 1), (0, -1)]


def BFS(x, y):
    queue = deque([(x, y)])
    check[x][y] = 1
    while queue:
        v = queue.popleft()
        v1 = v[0]
        v2 = v[1]
        if v1 == N-1 and v2 == M-1:
            break
        for i in range(len(dir)):
            a = dir[i][0]
            b = dir[i][1]
            if (v1+a < 0 or v1 + a >= N) or (v2 + b < 0 or v2 + b >= M) or arr[v1+a][v2+b] == 0:
                continue
            if arr[v1+a][v2+b] == 1:
                arr[v1+a][v2+b] = arr[v1][v2] + 1
                queue.append((v1+a, v2+b))


BFS(0, 0)
print(arr[N-1][M-1])
