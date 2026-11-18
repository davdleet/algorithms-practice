import sys

sys.stdin = open("D:\Projects\AA\BOJ\\23290\input.txt")
input = sys.stdin.readline
M, S = map(int, input().rstrip().split())

choices = [[k, j, i] for k in range(1, 5)
           for j in range(1, 5) for i in range(1, 5)]
dir = [[0, -1], [-1, -1], [-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1]]
s_dir = [0, [-1, 0], [0, -1], [1, 0], [0, 1]]
arr = [[[[], -1, []] for _ in range(4)] for __ in range(4)]

for i in range(M):
    fx, fy, d = map(int, input().rstrip().split())
    arr[fx-1][fy-1][0].append(d-1)
X, Y = map(int, input().rstrip().split())
X = X-1
Y = Y-1
# cast copy magic S times
for s in range(S):
    # move fishes
    for i in range(4):
        for j in range(4):
            if arr[i][j][0]:
                in_cnt = len(arr[i][j][0])
                for k in range(in_cnt):
                    # move existing
                    fish_dir = arr[i][j][k][0]
                    # prepare copies
                    arr[i][j][2].append(fish_dir)
                    next_dir = fish_dir
                    moved = False
                    for l in range(8):
                        a = dir[next_dir][0]
                        b = dir[next_dir][1]
                        # check if the fish can move there
                        if i + a >= 0 and i+a < 4 and j+b >= 0 and j+b < 4 and arr[i+a][j+b][1] == -1 and i+a != X and j + b != Y:
                            arr[i+a][j+b][0].append(next_dir)
                            moved = True
                            break
                        next_dir = (next_dir - 1) % 8
                    if moved:
                        arr[i][j][0].pop(k)

    biggest = -1
    biggest_idx = -1
    # move shark

    t_X = 0
    t_Y = 0
    # find best path
    for i in range(len(choices)):
        current_cnt = 0
        t_X = X
        t_Y = Y
        current_choice = choices[i]
        possible = True
        for j in range(len(current_choice)):
            dir_num = current_choice[j]
            c_a = s_dir[dir_num][0]
            c_b = s_dir[dir_num][1]
            if t_X+c_a >= 0 and t_X+c_a < 4 and t_Y+c_b >= 0 and t_Y+c_b < 4:
                current_cnt = current_cnt + len(arr[t_X+c_a][t_Y+c_b][0])
            else:
                possible = False
                break
            t_X = t_X + c_a
            t_Y = t_Y + c_b
        if possible:
            if current_cnt > biggest:
                biggest = current_cnt
                biggest_idx = i

    # leave fish smells
    for i in range(0, 3):
        b_a = s_dir[choices[biggest_idx][i]][0]
        b_b = s_dir[choices[biggest_idx][i]][1]
        arr[X+b_a][Y+b_b][0] = []
        arr[X+b_a][Y+b_b][1] = s
        X = X + b_a
        Y = Y + b_b

    # remove fish smells from s-2
    for i in range(4):
        for j in range(4):
            if arr[i][j][1] == (s-2):
                arr[i][j][1] = -1

    # complete fish duplication
    for i in range(4):
        for j in range(4):
            if arr[i][j][2]:
                arr[i][j][0].extend(arr[i][j][2])
                arr[i][j][2] = []

total = 0
for i in range(4):
    for j in range(4):
        if arr[i][j][0]:
            total += len(arr[i][j][0])
print(total)
