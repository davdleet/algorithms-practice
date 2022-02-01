import sys

sys.stdin = open("D:\Projects\AA\BOJ\\20921\input.txt", "r")
input = sys.stdin.readline

N, K = map(int, input().rstrip().rsplit())

D = {}
arr = []
for i in range(1, N + 1):
    D[i] = i-1
    arr.append(i)

target = K
count = 0
moved = 0
last = N
while count != K:
    if target >= (last-1):
        arr.remove(last)
        arr.insert(moved, last)
        count = count + last - 1
        target = target - (last - 1)
        last = last - 1
        moved += 1
    else:
        last = last - 1

for a in arr:
    print(a, end=" ")
