import sys

sys.stdin = open("D:\Projects\AA\BOJ\\10026\input.txt")
input = sys.stdin.readline

N = int(input().rstrip())

arr = [[0 for _ in range(N+2)]for __ in range(N+2)]
check = [[0 for _ in range(N+2)]for __ in range(N+2)]
R = 1
G = 2
B = 3

for i in range(1, N+1):
    line = list(input().rstrip())
    for j in range(len(line)):

        converted = 0
        if line[j] == 'R':
            converted = R
        elif line[j] == 'G':
            converted = G
        elif line[j] == 'B':
            converted = B
        arr[i][j+1] = converted

coords = [(-1, 0), (0, -1), (1, 0), (0, 1)]
n_cnt = 0
c_cnt = 0


def DFS(color, x, y, colorblind):

    for i in range(len(coords)):
        a = coords[i][0]
        b = coords[i][1]
        if arr[x+a][y+b] == color and check[x+a][y+b] == 0:
            check[x+a][y+b] = 1
            DFS(color, x+a, y+b, colorblind)
        elif colorblind and ((color == G or color) == R and (arr[x+a][y+b] == G or arr[x+a][y+b] == R)) and check[x+a][y+b] == 0:
            check[x+a][y+b] = 1
            DFS(color, x+a, y+b, colorblind)


for i in range(1, N + 1):
    for j in range(1, N+1):
        current_color = arr[i][j]
        if check[i][j] == 0:
            n_cnt += 1
            check[i][j] = 1
            DFS(current_color, i, j, False)
check = [[0 for _ in range(N+2)]for __ in range(N+2)]
for i in range(1, N + 1):
    for j in range(1, N+1):
        current_color = arr[i][j]
        if check[i][j] == 0:
            c_cnt += 1
            check[i][j] = 1
            DFS(current_color, i, j, True)
print(n_cnt, c_cnt)
