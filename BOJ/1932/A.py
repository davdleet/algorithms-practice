import sys

sys.stdin = open(
    "/Users/sungwonlee/Documents/Projects/algorithms-practice/BOJ/1932/input.txt", "r")

input = sys.stdin.readline


N = int(input().rstrip())

triangle = [[0 for j in range(i+1)] for i in range(N)]
paths = [[0 for j in range(i+1)] for i in range(N)]

for i in range(N):
    line = input().rstrip().split()
    for j in range(len(line)):
        paths[i][j] = int(line[j])
for i in range(N-2, -1, -1):
    for j in range(len(paths[i])):
        paths[i][j] = max(paths[i+1][j], paths[i+1][j+1]) + paths[i][j]
print(paths[0][0])
