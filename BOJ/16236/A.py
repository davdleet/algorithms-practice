import sys
from collections import deque
sys.stdin = open("D:\Projects\AA\BOJ\\16236\input.txt")
input = sys.stdin.readline

N = int(input().rstrip())

arr = []
dir = [(-1, 0), (0, -1), (0, 1), (1, 0)]
check = []

for i in range(N):
    line = list(map(int, input().rstrip().split()))
    arr.append(line)

baby = []
size = 2
eaten = 0
for i in range(N):
    for j in range(N):
        if arr[i][j] == 9:
            baby = [i, j]
            arr[i][j] = 0
time = 0


def BFS(x1, y1, d1):
    t = 0
    q = deque([(x1, y1, d1)])
    no_fish = True
    x2 = 0
    y2 = 0
    while q:
        current = q.popleft()
        x = current[0]
        y = current[1]
        d = current[2]
        break_flag = False
        for i in range(len(dir)):
            a = dir[i][0]
            b = dir[i][1]
            if (x+a >= N or x+a < 0) or (y+b >= N or y+b < 0) or check[x+a][y+b] == 1 or arr[x+a][y+b] > size:
                continue
            if arr[x+a][y+b] < size and arr[x+a][y+b] > 0:
                x2 = x+a
                y2 = y+b
                no_fish = False
                break_flag = True
                t = d+1
                break
            q.append((x+a, y+b, d+1))
            check[x+a][y+b] = 1
        if break_flag:
            break
        t += 1
    if no_fish:
        t = 0
    return (x2, y2, t)


def reset_check():
    global check
    check = [[0 for __ in range(N)] for _ in range(N)]


target = -1
while True:
    reset_check()
    temp = []
    result = BFS(baby[0], baby[1], 0)
    if result[2] == 0:
        break
    temp.append(result)
    reset_check()
    check[result[0]][result[1]] = 1
    another = BFS(baby[0], baby[1], 0)

    while(result[2] == another[2]):
        temp.append(another)
        reset_check()
        for i in range(len(temp)):
            check[temp[i][0]][temp[i][1]] = 1
        another = BFS(baby[0], baby[1], 0)

    temp.sort()

    result = temp[0]
    x = result[0]
    y = result[1]
    target = result[2]
    arr[x][y] = 0

    baby[0] = x
    baby[1] = y
    eaten += 1

    if eaten == size:
        eaten = 0
        size = size + 1
    time += target

print(time)
