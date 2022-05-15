import sys

sys.stdin = open("D:\Projects\AA\BOJ\\2644\input.txt")
input = sys.stdin.readline

N = int(input().rstrip())
X, Y = map(int, input().rstrip().split())
M = int(input().rstrip())
arr = [[10**9 for _ in range(N+1)] for __ in range(N+1)]
for i in range(M):
    A, B = map(int, input().rstrip().split())
    arr[A][B] = 1
    arr[B][A] = 1

for i in range(1, N+1):
    for j in range(1, N+1):
        for k in range(1, N+1):
            arr[i][k] = min(arr[i][k], arr[i][j] + arr[j][k])

ans = arr[X][Y]
if ans >= 10**9:
    print(-1, end='')
else:
    print(ans, end='')

# for i in range(1, N+1):
#     for j in range(1, N+1):
#         if arr[i][j] == 9999:
#             print("X", end=" ")
#         else:
#             print((arr[i][j]), end=" ")
#     print()
