import sys


sys.stdin = open("D:\Projects\AA\BOJ\\13458\input.txt")
input = sys.stdin.readline
N = int(input().rstrip())

arr = list(map(int, input().rstrip().split()))
line = list(map(int, input().rstrip().split()))
B = line[0]
C = line[1]

total = 0
for t in arr:
    covered = 0
    proc = 1
    covered = B
    sub_proc = 0
    if covered < t:
        remaining = t - covered
        sub_proc = remaining//C
        if (sub_proc * C) < remaining:
            sub_proc += 1
    total = total + proc + sub_proc

print(total)
