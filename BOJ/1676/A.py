import sys

sys.stdin = open("D:\Projects\AA\BOJ\\1676\input.txt")
input = sys.stdin.readline


N = int(input().rstrip())

f = 1
for i in range(1, N+1):
    f = f*i

str_f = str(f)
cnt = 0
for i in range(len(str_f) - 1, -1, -1):
    if str_f[i] != '0':
        break
    else:
        cnt += 1
print(cnt)
