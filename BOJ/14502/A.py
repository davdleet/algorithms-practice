import sys
from collections import deque
from copy import deepcopy
from copy import copy
sys.stdin = open("D:\Projects\AA\BOJ\\14502\input.txt")
input = sys.stdin.readline


def BFS(ax, ay, bx, by, cx, cy):
    global arr, i_q, N, M, initial_space, dir
    arr[ax][ay] = 1
    arr[bx][by] = 1
    arr[cx][cy] = 1
    visited = [[0 for _ in range(M)] for __ in range(N)]
    q = deepcopy(i_q)
    infected = len(q)
    while len(q):
        current = q.popleft()
        x = current[0]
        y = current[1]
        for i in range(4):
            a = dir[i][0]
            b = dir[i][1]
            if x+a >= 0 and x+a < N and y+b >= 0 and y+b < M and not visited[x+a][y+b] and arr[x+a][y+b] == 0:
                visited[x+a][y+b] = 1
                infected += 1
                q.append((x+a, y+b))
    arr[ax][ay] = 0
    arr[bx][by] = 0
    arr[cx][cy] = 0
    print("clean: ", initial_space - infected)
    return initial_space - infected


N, M = map(int, input().rstrip().split())

arr = [0 for __ in range(N)]
# visited = [[0 for _ in range(M)] for __ in range(N)]
dir = [[-1, 0], [1, 0], [0, 1], [0, -1]]
x_idx = [i for i in range(N)]
y_idx = [i for i in range(M)]
i_q = deque()
initial_space = 0
for i in range(N):
    line = list(map(int, input().rstrip().split()))
    arr[i] = line

for i in range(N):
    for j in range(M):
        current = arr[i][j]
        if current == 2:
            i_q.append((i, j))
        elif current == 0:
            initial_space += 1
max_clean = 0
print(initial_space)

possible = [(i, j) for j in range(M) for i in range(N)]

for i in range(len(possible)):
    point_a = possible[i]
    if arr[point_a[0]][point_a[1]] != 0:
        continue
    for j in range(len(possible)):
        point_b = possible[j]
        if arr[point_b[0]][point_b[1]] != 0 or point_b == point_a:
            continue
        for k in range(len(possible)):
            point_c = possible[k]
            if arr[point_c[0]][point_c[1]] != 0 or point_c == point_b or point_c == point_a:
                continue
            cnt = BFS(point_a[0], point_a[1], point_b[0],
                      point_b[1], point_c[0], point_c[1])
            max_clean = max(cnt, max_clean)

print(max_clean)
