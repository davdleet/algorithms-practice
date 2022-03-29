import sys

sys.stdin = open("D:\Projects\AA\BOJ\\11403\input.txt")
input = sys.stdin.readline

N = int(input().rstrip())

arr = [None for __ in range(N)]

for i in range(N):
    line = list(map(int, input().rstrip().split()))
    arr[i] = line

cn = set([])


def connected(idx):
    global cn
    for i in range(N):
        if arr[idx][i] == 1 and i not in cn:
            cn.add(i)
            connected(i)


for i in range(N):
    cn = set([])

    connected(i)
    for c in cn:
        arr[i][c] = 1

for i in range(N):
    for j in range(N):
        print(arr[i][j], end=' ')
    print()
