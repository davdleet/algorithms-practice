import sys

sys.stdin = open("D:\Projects\AA\BOJ\\14940\input.txt")
N, M = map(int, input().rstrip().split())

arr = []
g = ()
q = []
dis = [[0 for j in range(M)] for i in range(N)]
check = [[0 for j in range(M)] for i in range(N)]
for i in range(N):
    line = list(map(int, input().rstrip().split()))
    for j in range(len(line)):
        if line[j] == 2:
            g = (i, j, 0)
    arr.append(line)

for i in range(N):
    for j in range(M):
        dis[i][j] = 0

add = [(1, 0), (0, 1), (0, -1), (-1, 0)]

q.append(g)
check[g[0]][g[1]] = 1

while len(q) != 0:
    current = q[0]
    x = current[0]
    y = current[1]
    d = current[2]
    q.pop(0)
    for i in range(len(add)):
        a = add[i][0]
        b = add[i][1]
        if (x+a < 0 or x+a >= N) or (y+b < 0 or y+b >= M):
            continue
        if check[x+a][y+b] == 0 and arr[x+a][y+b] != 0 and arr[x+a][y+b] != 2:
            check[x+a][y+b] = 1
            dis[x+a][y+b] = d+1
            q.append((x+a, y+b, d+1))

for i in range(N):
    for j in range(M):
        if arr[i][j] != 0 and check[i][j] == 0:
            print(-1, end=" ")
        else:
            print(dis[i][j], end=" ")
    print()
