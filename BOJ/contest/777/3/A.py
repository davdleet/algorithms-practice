import sys

sys.stdin = open("D:\Projects\AA\BOJ\contest\\777\\3\input.txt")
input = sys.stdin.readline

N, M = map(int, input().rstrip().split())

arr = []

groups = (("I", "E"), ("N", "S"), ("T", "F"), ("J", "P"))
MBTI = []
dir = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]
temp = ''
for i in range(2):
    t1 = groups[0][i]
    for j in range(2):
        t2 = groups[1][j]
        for k in range(2):
            t3 = groups[2][k]
            for l in range(2):
                t4 = groups[3][l]
                MBTI.append(t1+t2+t3+t4)

for i in range(N):
    line = list(input().rstrip())
    arr.append(line)

ans = 0

for i in range(len(arr)):
    # for current coordinate
    for j in range(len(arr[i])):
        # search all directions
        for k in range(len(dir)):
            string = arr[i][j]
            a = dir[k][0]
            b = dir[k][1]
            # advance 3 times
            for l in range(1, 4):
                x = i + a * l
                y = j + b * l
                if (x >= N or x < 0) or (y >= M or y < 0):
                    break
                string += arr[x][y]
            if string in MBTI:
                ans += 1

print(ans)
