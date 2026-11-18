import sys
from collections import deque

sys.stdin = open(
    "D:\Projects\AA\BOJ\\20056\input.txt")
input = sys.stdin.readline

N, M, K = map(int, input().rstrip().split())

dir = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]

arr = [[[] for _ in range(N)] for __ in range(N)]

q = deque()

for i in range(M):
    r, c, m, s, d = map(int, input().rstrip().split())
    arr[r-1][c-1].append([m, s, d])
    q.append([r-1, c-1])


for ___ in range(K):
    # number 1, move fireballs
    while q:
        current = q.popleft()
        r = current[0]
        c = current[1]
        # move fireballs in r, c
        cnt = len(arr[r][c])
        for i in range(cnt):
            m = arr[r][c][0][0]
            s = arr[r][c][0][1]
            d = arr[r][c][0][2]
            a = dir[d][0] * s
            b = dir[d][1] * s
            new_x = (r + a) % N
            new_y = (c + b) % N
            arr[r][c].pop(0)
            print(new_x, new_y)
            # if new_x != r and new_y != c:
            arr[new_x][new_y].append([m, s, d])
    # number 2, merge fireballs
    for i in range(N):
        for j in range(N):
            if len(arr[i][j]) > 1:
                even_cnt = 0
                odd_cnt = 0
                m_sum = 0
                s_sum = 0
                cnt = len(arr[i][j])
                for k in range(len(arr[i][j])):
                    m = arr[i][j][k][0]
                    s = arr[i][j][k][1]
                    d = arr[i][j][k][2]
                    m_sum += m
                    s_sum += s
                    if d % 2 == 0:
                        even_cnt += 1
                    else:
                        odd_cnt += 1
                arr[i][j] = []
                split_m = (m_sum // 5)
                split_s = (s_sum // cnt)
                split_dir = []
                if (even_cnt == cnt) or (odd_cnt == cnt):
                    split_dir = [0, 2, 4, 6]
                else:
                    split_dir = [1, 3, 5, 7]
                if split_m:
                    for k in range(4):
                        arr[i][j].append([split_m, split_s, split_dir[k]])
            if len(arr[i][j]):
                q.append([i, j])

ans = 0
for i in range(N):
    for j in range(N):
        if len(arr[i][j]):
            for k in range(len(arr[i][j])):
                ans += arr[i][j][k][0]
print(ans)
