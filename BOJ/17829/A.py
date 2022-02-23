import sys

sys.stdin = open("D:\Projects\AA\BOJ\\17829\input.txt")
input = sys.stdin.readline

N = int(input().rstrip())

arr = [[0 for _ in range(N)] for __ in range(N)]


for i in range(N):
    line = input().rstrip().split()
    for j in range(len(line)):
        arr[i][j] = int(line[j])

while(len(arr) != 1):
    next_arr = []
    for i in range(0, len(arr) - 1, 2):
        temp_arr = []
        for j in range(0, len(arr[i])-1, 2):
            a = [arr[i][j], arr[i][j+1], arr[i+1][j], arr[i+1][j+1]]
            m = max(a)
            a.remove(m)
            s = max(a)
            temp_arr.append(s)
        next_arr.append(temp_arr)
    arr = next_arr


print(arr[0][0])
