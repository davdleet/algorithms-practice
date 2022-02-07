import sys

sys.stdin = open('D:\Projects\AA\BOJ\\2812\input.txt')
input = sys.stdin.readline

N, K = list(map(int, input().rstrip().split()))

num = list(map(int, input().rstrip()))
ans = []
for i in range(len(num)):
    if len(ans) == N - K:
        break
    if len(num) + len(ans) == N - K:
        ans.append(num[0])
        num = num[1:]
    # length of num + ans is more than N - K
    else:
        diff = N - K - len(ans) - len(num)
        max_idx = num.index(max(num[:-diff+1]))
        ans.append(num[max_idx])
        num = num[max_idx+1:]

for c in ans:
    print(c, end='')

# base = 10 ** (N-K-1)
# ans = 0
# for c in num:
#     ans = ans + c * base
#     base = base // 10
# print(ans)
