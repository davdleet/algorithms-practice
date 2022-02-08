import sys

sys.stdin = open('D:\Projects\AA\BOJ\\2812\input.txt')
input = sys.stdin.readline

N, K = list(map(int, input().rstrip().split()))

num = list(map(int, input().rstrip()))
ans = []
count = 0
for i in range(len(num)):
    now = num[i]
    if len(ans) == 0 or now <= ans[-1]:
        None
    else:
        while len(ans) != 0 and now > ans[-1] and count < K:
            ans.pop()
            count += 1
    ans.append(now)

while count < K:
    ans.pop()
    count += 1

for c in ans:
    print(c, end='')
