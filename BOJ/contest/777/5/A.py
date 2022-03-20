import sys

sys.stdin = open('D:\Projects\AA\BOJ\contest\\777\\5\input.txt')
input = sys.stdin.readline

N = int(input().rstrip())
cs, eg = map(int, input().rstrip().split())

cs_count = 0
eg_count = N**2
z_count = 0
dir = [(-1, 0), (0, 1), (1, 0), (0, -1)]

arr = [[2 for _ in range(N)] for __ in range(N)]
for i in range(len(arr)):
    break_flag = False
    for j in range(len(arr[i])):
        if cs_count == cs:
            break_flag = True
            break
        if arr[i][j] == 2:
            eg_count -= 1
        arr[i][j] = 1
        cs_count += 1
        for k in range(len(dir)):
            a = dir[k][0]
            b = dir[k][1]
            if (i+a >= N or i+a < 0) or (j+b >= N or j+b < 0) or arr[i+a][j+b] != 2:
                continue
            arr[i+a][j+b] = 0
            z_count += 1
            eg_count -= 1
    if break_flag:
        break

for i in range(N):
    for j in range(N):
        if arr[i][j] == 2 and eg_count > eg:
            z_count += 1
            arr[i][j] = 0
            eg_count -= 1

if cs_count == cs and eg_count == eg:
    print(1)
else:
    print(-1)
    sys.exit(0)


for i in range(N):
    for j in range(N):
        print(arr[i][j], end='')
    print()
