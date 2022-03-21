import sys

sys.stdin = open('D:\Projects\AA\study-book\\180\input.txt')
input = sys.stdin.readline

N = int(input().rstrip())

arr = []

for i in range(N):
    name, val = input().rstrip().split()
    arr.append((name, int(val)))


arr.sort(key=lambda x: x[1])
for i in range(len(arr)):
    print(arr[i][0], end=' ')
