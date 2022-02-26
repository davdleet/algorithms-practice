import sys

sys.stdin = open("D:\Projects\AA\study-book\p92\input.txt")
input = sys.stdin.readline


N, M, K = map(int, input().rstrip().split())
arr = list(map(int, input().rstrip().split()))

arr.sort(reverse=True)

sum = 0
sec = False
cnt = 0

# naive approach
# for i in range(M):
#     if cnt == K:
#         cnt = 0
#         sum += arr[1]
#     else:
#         sum += arr[0]
#         cnt += 1

# calculate add times
sum = (M // K) * (arr[0] * K + arr[1]) + (M % (K + 1) * arr[0])


print(sum)
