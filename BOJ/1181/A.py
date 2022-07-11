import sys

sys.stdin = open("D:\Projects\AA\BOJ\\1181\input.txt")
input = sys.stdin.readline


N = int(input().rstrip())

arr = []

for i in range(N):
    temp = str(input().rstrip())
    if temp not in arr:
        arr.append(temp)

arr.sort(key=lambda x: (len(x), x))
for s in arr:
    print(s)
