import sys

sys.stdin = open('D:\Projects\AA\BOJ\\18115\input.txt')
input = sys.stdin.readline

N = int(input().rstrip())

used = list(map(int, input().rstrip().split()))

arr = [i for i in range(1, N+1)]
result = []

for i in range(N-1, -1, -1):
    if used[i] == 1:
        result.insert(0, arr[0])
        arr.remove(arr[0])
    elif used[i] == 2:
        result.insert(1, arr[0])
        arr.remove(arr[0])
    elif used[i] == 3:
        result.append(arr[0])
        arr.remove(arr[0])

print(result)
