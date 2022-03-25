import sys
from collections import deque
sys.stdin = open('D:\Projects\AA\BOJ\\14500\input.txt')
input = sys.stdin.readline

N, M = map(int, input().rstrip().split())
arr = []

dir = [(-1, 0), (1, 0), (0, -1), (0, 1)]
diagonal = [(1, 1), (-1, -1)]

for i in range(N):
    line = list(map(int, input().rstrip().split()))
    arr.append(line)

ans = 0

level = 4


def DFS(xi, yi):
    ch = {}
    global ans, level
    cnt = 0
    st = deque([(xi, yi, cnt, 0)])
    ch[(xi, yi)] = 1
    while st:
        current = st.pop()
        x = current[0]
        y = current[1]
        l = current[2]
        sum = current[3]
        sum = sum + arr[x][y]
        if l == level - 1:
            if sum > ans:
                ans = sum
            continue
        # handle the T shape
        for i in range(4):
            a = dir[i][0]
            b = dir[i][1]
            if (x+a < 0 or x+a >= N) or (y+b < 0 or y+b >= M):
                continue
            try:
                t = ch[((x+a), (y+b))]
                continue
            except:
                ch[((x+a), (y+b))] = 1
            st.append((x+a, y+b, l+1, sum))


for i in range(N):
    for j in range(M):
        DFS(i, j)


print(ans)
