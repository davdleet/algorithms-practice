import sys

sys.stdin = open("D:\Projects\AA\study-book\\150\input.txt")
input = sys.stdin.readline

N, M = map(int, input().rstrip().split())
arr = []
check = [[0 for _ in range(M)] for __ in range(N)]

for i in range(N):
    line = list(map(int, list(input().rstrip())))
    arr.append(line)

dir = [(1, 0), (-1, 0), (0, 1), (0, -1)]


def DFS(y, x):
    check[y][x] = 1
    for i in range(len(dir)):
        a = dir[i][0]
        b = dir[i][1]
        if (y+a < 0 or y+a >= N) or (x+b < 0 or x+b >= M):
            continue
        if arr[y+a][x+b] == 0 and check[y+a][x+b] == 0:
            DFS(y+a, x+b)


count = 0

for i in range(N):
    for j in range(M):
        if check[i][j] == 0 and arr[i][j] == 0:
            DFS(i, j)
            count += 1


print(count)
