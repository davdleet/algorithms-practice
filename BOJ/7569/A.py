from copy import deepcopy
import sys
from collections import deque
sys.stdin = open("D:\Projects\AA\BOJ\\7569\input.txt")
input = sys.stdin.readline
M, N, H = map(int, input().rstrip().split())

arr = []

for i in range(H):
    box = []
    for j in range(N):
        line = list(map(int, input().rstrip().split()))
        box.append(line)
    arr.append(box)

ans = 0


dir = [(-1, 0, 0), (1, 0, 0), (0, 1, 0), (0, -1, 0), (0, 0, -1), (0, 0, 1)]

ch_1 = [[[0 for _ in range(M)] for __ in range(N)] for ___ in range(H)]
ch = deepcopy(ch_1)


def BFS(x1, y1, z1):
    global ch, dir, arr
    q = deque([(x1, y1, z1)])
    possible = False
    while(q):
        current = q.popleft()
        x = current[0]
        y = current[1]
        z = current[2]
        break_flag = False
        for i in range(len(dir)):
            a = dir[i][0]
            b = dir[i][1]
            c = dir[i][2]
            # skip if out of bounds, blocked, or already visited
            if (x+a < 0 or x+a >= H) or (y+b < 0 or y+b >= N) or (z+c < 0 or z+c >= M) or ch[x+a][y+b][z+c] == 1 or arr[x+a][y+b][z+c] == -1:
                continue
            else:
                # if adjecent element is 1, the area can be ripened
                if arr[x+a][y+b][z+c] == 1:
                    possible = True
                else:
                    ch[x+a][y+b][z+c] = 1
                    q.append((x+a, y+b, z+c))
        if break_flag:
            break
    return possible

# check if the entire arr is ripe
# if ripe is -1, its impossible
# ripe is 0, it is not ripe
# ripe is 1, it is ripe


def check():
    global ans, dir, ch
    ripe = 1
    for i in range(H):
        flag1 = False
        for j in range(N):
            flag2 = False
            for k in range(M):
                if arr[i][j][k] == 0 and ch[i][j][k] == 0:
                    possible = BFS(i, j, k)
                    # if impossible, break the entire loop, set ans to -1
                    if not possible:
                        ripe = -1
                        ans = -1
                        flag2 = True
                    else:
                        ripe = 0
            if flag2:
                flag1 = True
                break
        if flag1:
            break
    return ripe


ch_val = check()
while ch_val == 0:
    ch = deepcopy(ch_1)
    ans += 1
    for i in range(H):
        for j in range(N):
            for k in range(M):
                x = i
                y = j
                z = k
                # ripen adjacent elements if current is ripe
                if arr[i][j][k] == 1 and ch[i][j][k] == 0:
                    for l in range(len(dir)):
                        a = dir[l][0]
                        b = dir[l][1]
                        c = dir[l][2]
                        if (x+a < 0 or x+a >= H) or (y+b < 0 or y+b >= N) or (z+c < 0 or z+c >= M) or (arr[x+a][y+b][z+c] != 0) or ch[x+a][y+b][z+c] == 1:
                            continue
                        else:
                            ch[x+a][y+b][z+c] = 1
                            arr[x+a][y+b][z+c] = 1

    ch = deepcopy(ch_1)
    ch_val = check()
print(ans)
