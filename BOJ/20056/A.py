import sys
from collections import deque

sys.stdin = open(
    "/Users/sungwonlee/Documents/Projects/algorithms-practice/BOJ/20056/input.txt")
input = sys.stdin.readline

N, M, K = map(int, input().rstrip().split())

dir = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]

arr = [[[] for _ in range(N+1)] for __ in range(N+1)]

q = deque()

for i in range(M):
    r, c, m, s, d = map(int, input().rstrip().split())
    arr[r][c].append([m, s, d])
    q.append([r, c, 0])

dct = {}

time = 0

for _ in range(K):
    while len(q):
        current = q.popleft()
        r = current[0]
        c = current[1]
        t = current[2]
        print(r, c, t)
        # move fireballs in r, c
        cnt = len(arr[r][c])
        for i in range(cnt):
            m = arr[r][c][0][0]
            s = arr[r][c][0][1]
            d = arr[r][c][0][2]
            a = dir[d][0] * s
            b = dir[d][1] * s
            arr[r][c].pop(0)

            new_x = (abs(r + a) % N)
            new_y = (abs(c + b) % N)
            arr[new_x][new_y].append([m, s, d])
            print(f"time, t: {time, t}")
            # update fireballs after moving all
    for i in range(1, N+1):
        for j in range(1, N+1):
            if len(arr[r][c]) > 1:
                all_even = True
                all_odd = True
                m_sum = 0
                s_sum = 0
                cnt = len(arr[r][c])
                for k in range(cnt):
                    m = arr[r][c][0][0]
                    s = arr[r][c][0][1]
                    d = arr[r][c][0][2]
                    m_sum += m
                    s_sum += s
                    if d % 2 == 0:
                        all_odd = False
                    else:
                        all_even = False
                    arr[r][c].pop(0)
                split_m = int(m_sum / 5)
                split_s = int(s_sum / cnt)
                split_dir = [1, 3, 5, 7]
                if all_even or all_odd:
                    split_dir = [0, 2, 4, 6]
                if split_m > 0:
                    for k in range(4):
                        arr[r][c].append([split_m, split_s, split_dir[k]])
                    q.append([r, c, t+1])
            elif len(arr[r][c]):
                q.append([r, c, t+1])
ans = 0
for i in range(1, N+1):
    for j in range(1, N+1):
        if len(arr[i][j]):
            for k in range(len(arr[i][j])):
                ans += arr[i][j][k][0]
print(arr)
print(ans)
