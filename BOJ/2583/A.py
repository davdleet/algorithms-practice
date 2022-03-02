import sys

sys.setrecursionlimit(10**6)
sys.stdin = open(
    "/Users/sungwonlee/Documents/Projects/algorithms-practice/BOJ/2583/input.txt")
input = sys.stdin.readline
M, N, K = map(int, input().rstrip().split())

arr = [[0 for _ in range(N)] for __ in range(M)]

check = [[0 for _ in range(N)] for __ in range(M)]

for i in range(K):
    line = list(map(int, input().rstrip().split()))
    c1 = (line[0], line[1])
    c2 = (line[2], line[3])
    for j in range(c1[1], c1[1]+(c2[1] - c1[1])):
        for k in range(c1[0], c1[0]+(c2[0] - c1[0])):
            arr[j][k] = 1

dir = [(-1, 0), (1, 0), (0, -1), (0, 1)]


def DFS(x, y):
    t = False
    for i in range(len(dir)):
        a = dir[i][0]
        b = dir[i][1]
        if (x+a < 0 or x+a >= N) or (y+b < 0 or y+b >= M):
            continue
        if arr[x+a][y+b] == 0 and check[x+a][y+b] == 0:
            print(x+a, y+b)
            t = True
            check[x+a][y+b] = 1
            return DFS(x+a, y+b)+1
    if not t:
        return 1


areas = []
for i in range(M):
    for j in range(N):
        if arr[i][j] == 0 and check[i][j] == 0:
            check[i][j] = 1
            area = DFS(i, j)
            areas.append(area)
            print(area)
            print('\n')
areas.sort()
print(areas)
