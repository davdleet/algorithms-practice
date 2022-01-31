import sys

sys.stdin = open("D:\Projects\AA\BOJ\\1931\input.txt", "r")
input = sys.stdin.readline

N = int(input().rstrip())

schedule = []
lines = []

for i in range(N):
    s, e = map(int, input().rstrip().split())
    lines.append((s, e))

lines.sort(key=lambda x: (x[1], x[0]))
print(lines)
count = 0

schedule.append(-1)
for i in range(len(lines)):
    if schedule[-1] <= lines[i][0]:
        schedule.append(lines[i][1])
        count += 1
print(count)
