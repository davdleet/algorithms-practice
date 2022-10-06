import sys
import copy
sys.stdin = open("D:\Projects\AA\BOJ\\1152\input.txt")
input = sys.stdin.readline

N = int(input().rstrip())

board = [[0 for _ in range(N+2)] for __ in range(N+2)]
head_dir = [[0 for _ in range(N+2)] for __ in range(N+2)]
# dir_idx + 1 means turning right, dir_idx - 1 is turning left
dir_idx = 0
dir = [(0, 1), (1, 0), (0, -1), (-1, 0)]


K = int(input().rstrip())
for i in range(K):
    line = list(map(int, input().rstrip().split()))
    a = line[0]
    b = line[1]
    board[a][b] = 1

L = int(input().rstrip())
dir_change = {}
for i in range(L):
    line = input().rstrip().split()
    t = int(line[0])
    d = line[1]
    if d == "L":
        d = -1
    else:
        d = 1
    dir_change[t] = d


time = 1
head = [1, 1]
tail = [1, 1]
board[1][1] = 2
while True:
    x = head[0]
    y = head[1]
    a = dir[dir_idx][0]
    b = dir[dir_idx][1]
    head_dir[x][y] = dir_idx
    new_x = x + a
    new_y = y + b
    # hit wall or own body
    if board[new_x][new_y] == 2 or new_x < 1 or new_x > N or new_y < 1 or new_y > N:
        break
    # found an apple
    elif board[new_x][new_y] == 1:
        board[new_x][new_y] = 2
        head[0] = new_x
        head[1] = new_y
    # just moved forward
    else:
        x1 = tail[0]
        y1 = tail[1]
        board[new_x][new_y] = 2
        board[x1][y1] = 0
        head[0] = new_x
        head[1] = new_y
        tail[0] = x1 + dir[head_dir[x1][y1]][0]
        tail[1] = y1 + dir[head_dir[x1][y1]][1]
    try:
        d = dir_change[time]
        dir_idx = dir_idx + d
        if dir_idx == 4:
            dir_idx = 0
        elif dir_idx == -1:
            dir_idx = 3
    except:
        None
    time += 1
print(time)
