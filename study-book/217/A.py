import sys

sys.stdin = open("D:\Projects\AA\study-book\\217\input.txt")
input = sys.stdin.readline

X = int(input().rstrip())


arr = [0 for _ in range(X+1)]

for i in range(2, len(arr)):
    arr[i] = arr[i-1] + 1
    if i % 5 == 0:
        arr[i] = min(arr[i//5] + 1, arr[i])
    if i % 3 == 0:
        arr[i] = min(arr[i//3] + 1, arr[i])
    if i % 2 == 0:
        arr[i] = min(arr[i//2] + 1, arr[i])

print(arr[X])
