import sys

sys.stdin = open("D:\Projects\AA\BOJ\\23559\input.txt", "r")
input = sys.stdin.readline

N, X = map(int, input().rstrip().split())

arr = []
for i in range(N):
    a, b = map(int, input().rstrip().split())
    arr.append((a, b))
arr.sort(key=lambda x: x[0] - x[1], reverse=True)
a_times = (X - 1000 * N)//4000


sum = 0
decided = []
for i in range(N):
    if a_times > 0 and arr[i][0] > arr[i][1]:
        sum += arr[i][0]
        a_times -= 1
    else:
        sum += arr[i][1]
print(sum)
