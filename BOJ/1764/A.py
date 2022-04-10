import sys

sys.stdin = open("D:\Projects\AA\BOJ\\1764\input.txt")
input = sys.stdin.readline

N, M = map(int, input().rstrip().split())

d1 = {}
d2 = {}
ans = []
count = 0
for i in range(N):
    temp = str(input().rstrip())
    d1[temp] = 1


for i in range(M):
    temp = str(input().rstrip())
    d2[temp] = 1

for k in d1.keys():
    try:
        t = d2[k]
        ans.append(k)
        count += 1
    except:
        None

print(count)
ans.sort()
for a in ans:
    print(a)
