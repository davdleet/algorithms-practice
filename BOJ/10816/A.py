import sys

sys.stdin = open('D:\Projects\AA\BOJ\\10816\input.txt', 'r')
input = sys.stdin.readline

N = int(input().rstrip())
d = {}
arr = list(map(int, input().rstrip().split()))
for i in range(len(arr)):
    num = arr[i]
    try:
        d[num] += 1
    except:
        d[num] = 1
M = int(input().rstrip())
r = list(map(int, input().strip().split()))
for i in range(len(r)):
    try:
        print(d[r[i]], end=' ')
    except:
        print(0, end=' ')
