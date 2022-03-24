import sys
from collections import deque

sys.stdin = open(
    "/Users/sungwonlee/Documents/Projects/algorithms-practice/BOJ/7569/input.txt")
input = sys.stdin.readline
M, N, H = map(int, input().rstrip().split())

arr = [[input().split() for _ in range(N)] for __ in range(H)]

ans = 0


dir = [(-1, 0, 0), (1, 0, 0), (0, 1, 0), (0, -1, 0), (0, 0, -1), (0, 0, 1)]

ch = []


ch = [[[0 for _ in range(M)] for __ in range(N)] for ___ in range(H)]


def BFS():
    q = deque([])
    ripe = 1
    for i in range(H):
        for j in range(N):
            for k in range(M):
                if arr[i][j][k] == '1':
                    q.append((i, j, k, 0))
                elif arr[i][j][k] == '0':
                    ripe = 0
    if ripe:
        return 0
    ans = 0
    while q:
        current = q.popleft()
        x = current[0]
        y = current[1]
        z = current[2]
        d = current[3]
        for i in range(6):
            a = dir[i][0]
            b = dir[i][1]
            c = dir[i][2]
            if (x+a < 0 or x+a >= H) or (y+b < 0 or y+b >= N) or (z+c < 0 or z+c >= M) or arr[x+a][y+b][z+c] != '0' or ch[x+a][y+b][z+c] == 1:
                continue
            arr[x+a][y+b][z+c] = '1'
            q.append((x+a, y+b, z+c, d+1))
            ch[x+a][y+b][z+c] = 1
        ans = d
    for i in range(H):
        for j in range(N):
            for k in range(M):
                if arr[i][j][k] == '0':
                    return -1
    return ans


print(BFS())
