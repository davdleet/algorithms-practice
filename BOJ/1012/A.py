import sys
from collections import deque
sys.stdin = open('D:\Projects\AA\BOJ\\1012\input.txt')
input = sys.stdin.readline

T = int(input().rstrip())

arr = []
check = {}

dir = [(1, 0), (-1, 0), (0, 1), (0, -1)]


def BFS(x1, y1, N, M):
    q = deque([(x1, y1)])
    while q:
        first = q.popleft()
        x = first[0]
        y = first[1]
        for i in range(len(dir)):
            a = dir[i][0]
            b = dir[i][1]
            if (x+a >= N or x+a < 0) or (y+b >= M or y+b < 0) or arr[x+a][y+b] == 0:
                continue
            try:
                test = check[(x+a, y+b)]
                continue
            except:
                None
                q.append((x+a, y+b))
                check[(x+a, y+b)] = 1


for t in range(T):
    count = 0
    N, M, K = map(int, input().rstrip().split())
    arr = [[0 for __ in range(M)] for _ in range(N)]
    check = {}
    for i in range(K):
        x, y = map(int, input().rstrip().split())
        arr[x][y] = 1
    for i in range(N):
        for j in range(M):
            current = arr[i][j]
            if current == 1:
                try:
                    test = check[(i, j)]
                    continue
                except:
                    None
                    check[(i, j)] = 1
                    count += 1
                    BFS(i, j, N, M)
    print(count)
