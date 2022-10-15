import sys

sys.stdin = open("D:\Projects\AA\BOJ\\21610\input.txt")
input = sys.stdin.readline
N, M = map(int, input().rstrip().split())


arr = [[0 for _ in range(N+1)] for __ in range(N+1)]
dir = [0, [0, -1], [-1, -1], [-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1]]
# initialize arr
for i in range(N):
    line = list(map(int, input().rstrip().split()))
    for j in range(len(line)):
        t = line[j]
        arr[i+1][j+1] = t

clouds = [[N, 1], [N, 2], [N-1, 1], [N-1, 2]]

for m in range(M):
    d, s = map(int, input().rstrip().split())
    moved_clouds = []
    # move the clouds
    a = dir[d][0]
    b = dir[d][1]
    for i in range(len(clouds)):
        x = clouds[i][0]
        y = clouds[i][1]
        # print(f"{x} + {a * s} = ", end="")
        n_x = (x + a * s) % N or N
        # print(x)
        # print(f"{y} + {b * s} = ", end="")
        n_y = (y + b * s) % N or N
        # print(y)
        moved_clouds.append([n_x, n_y])
    dct = {}
    # water spaces in moved clouds
    for i in range(len(moved_clouds)):
        # dictionary for checking moved clouds later
        mc_x = moved_clouds[i][0]
        mc_y = moved_clouds[i][1]
        dct[(mc_x, mc_y)] = 1
        arr[mc_x][mc_y] += 1
    for i in range(len(moved_clouds)):
        mc_x_1 = moved_clouds[i][0]
        mc_y_1 = moved_clouds[i][1]
        up = (mc_x_1 - 1) % N or N
        down = (mc_x_1 + 1) % N or N
        left = (mc_y_1 - 1) % N or N
        right = (mc_y_1 + 1) % N or N
        copy_cnt = 0
        # upper left
        if up < mc_x_1 and left < mc_y_1 and arr[up][left]:
            copy_cnt += 1
        # upper right
        if up < mc_x_1 and right > mc_y_1 and arr[up][right]:
            copy_cnt += 1
        # lower left
        if down > mc_x_1 and left < mc_y_1 and arr[down][left]:
            copy_cnt += 1
        # lower right
        if down > mc_x_1 and right > mc_y_1 and arr[down][right]:
            copy_cnt += 1
        arr[mc_x_1][mc_y_1] = arr[mc_x_1][mc_y_1] + copy_cnt
    clouds = []
    for i in range(1, N+1):
        for j in range(1, N+1):
            if arr[i][j] >= 2:
                try:
                    ch = dct[(i, j)]
                except:
                    clouds.append([i, j])
                    arr[i][j] -= 2
ans = 0
for i in range(1, N+1):
    for j in range(1, N+1):
        ans += arr[i][j]
print(ans)
