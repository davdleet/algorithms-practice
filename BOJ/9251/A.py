import sys

sys.stdin = open("D:\Projects\AA\BOJ\9251\input.txt")
input = sys.stdin.readline

A = input().rstrip()
B = input().rstrip()

dp = [[0 for _ in range(1001)] for __ in range(1001)]


def count(a, b):
    cnt = 0
    for i in range(len(a)):
        if a[i] == b[cnt]:
            cnt += 1
            if cnt >= len(b):
                break
    return cnt


j = 0

for i in range(len(A)):
    a = A[i]
    for j in range(len(B)):
        b = B[j]
        add1 = 0
        add2 = 0
        if i-1 >= 0:
            add1 = dp[i-1][j]
        if j-1 >= 0:
            add2 = dp[i][j-1]
        if a == b:
            add3 = 1
            if i-1 >= 0 and j-1 >= 0:
                add3 = dp[i-1][j-1] + 1
            dp[i][j] = add3

        else:
            dp[i][j] = max(add1, add2)


print(dp[len(A)-1][len(B)-1], end="")
