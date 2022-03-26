import sys
from collections import deque
sys.stdin = open('D:\Projects\AA\BOJ\\14500\input.txt')
input = sys.stdin.readline

sys.setrecursionlimit(10**5)
N, M = map(int, input().rstrip().split())
arr = []

dir = [(-1, 0), (1, 0), (0, -1), (0, 1)]

for i in range(N):
    line = list(map(int, input().rstrip().split()))
    arr.append(line)

ans = 0

level = 4

ch = {}

xi = 0
yi = 0


def DFS(x, y, l, sum):
    global ch, ans, xi, yi
    ch[(x, y)] = 1
    sum = sum + arr[x][y]
    if l == level - 1:
        if sum > ans:
            ans = sum
        return
    # handle the T shape
    elif l == level - 3:
        direction = ((x - xi), (y - yi))
        p1 = (direction[1], direction[0])
        p2 = (-direction[1], -direction[0])
        v0 = 0
        v1 = 0
        v2 = 0
        if ((x+direction[0] >= N) or (x+direction[0] < 0)) or ((y + direction[1] >= M) or (y + direction[1] < 0)):
            None
        else:
            v0 = (arr[x + direction[0]][y + direction[1]])
        if ((x + p1[0] >= N) or (x + p1[0] < 0)) or ((y + p1[1] >= M) or (y + p1[1] < 0)):
            None
        else:
            v1 = arr[x + p1[0]][y + p1[1]]
        if ((x + p2[0] >= N) or (x + p2[0] < 0)) or ((y + p2[1] >= M) or (y + p2[1] < 0)):
            None
        else:
            v2 = arr[x + p2[0]][y + p2[1]]
        if sum + v0 + v1 > ans:
            ans = sum + v0 + v1
        if sum + v0 + v2 > ans:
            ans = sum + v0 + v1
    for i in range(len(dir)):
        a = dir[i][0]
        b = dir[i][1]
        if (x+a < 0 or x+a >= N) or (y+b < 0 or y+b >= M):
            continue
        try:
            t = ch[((x+a), (y+b))]
            if t == 1:
                continue
        except:
            # ch[((x+a), (y+b))] = 1
            None
        DFS(x+a, y+b, l+1, sum)
        ch[((x+a), (y+b))] = 0
    ch[(x, y)] = 0


for i in range(N):
    for j in range(M):
        xi = i
        yi = j
        DFS(i, j, 0, 0)


print(ans)
