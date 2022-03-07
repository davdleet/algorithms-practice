import sys

sys.stdin = open("D:\Projects\AA\study-book\\118\input.txt")
input = sys.stdin.readline

N, M = map(int, input().rstrip().split())
x, y, d = map(int, input().rstrip().split())

directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
arr = []
check = [[0 for _ in range(M)] for __ in range(N)]
for i in range(N):
    line = list(map(int, input().rstrip().split()))
    arr.append(line)

cnt = 0
while True:
    all_flag = True
    for i in range(len(directions)):
        if d == len(directions)-1:
            d = 0
        else:
            d = d + 1
        a = directions[d][0]
        b = directions[d][1]
        if arr[x+a][y+b] == 0 and check[x+a][y+b] == 0:
            all_flag = False
            cnt += 1
            check[x+a][y+b] = 1
            x += a
            y += b
            break
    if all_flag:
        back = d - 2
        if arr[x+directions[back][0]][y+directions[back][1]] == 0:
            x += directions[back][0]
            y += directions[back][1]
        else:
            break

print(cnt)
