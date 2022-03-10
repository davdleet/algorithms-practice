import sys

sys.stdin = open("D:\Projects\AA\BOJ\\18111\input.txt")
input = sys.stdin.readline

N, M, B = map(int, input().rstrip().split())
inventory = B
arr = []

for i in range(N):
    line = list(map(int, input().split()))
    arr.append(line)

dir = [(1, 0), (-1, 0), (0, 1), (0, -1)]

time = 0

for i in range(N):
    for j in range(M):
        current = arr[i][j]
        temp = [current]
        for k in range(len(dir)):
            a = dir[k][0]
            b = dir[k][1]
            if (i+a < 0 or i+a >= N) or (j+b < 0 or j+b >= M):
                continue
            temp.append(arr[i+a][j+b])
        m = len(temp) // 2
        temp.sort()
        if current == temp[m]:
            continue
        elif current < temp[m]:
            inventory -= (temp[m] - current)
            arr[i][j] = current + (temp[m] - current)
            time = time + abs(temp[m] - current) * 1
        else:
            inventory += (temp[m] - current)
            arr[i][j] = current - (temp[m] - current)
            time = time + abs(temp[m] - current) * 2
print(time, arr[0][0])
