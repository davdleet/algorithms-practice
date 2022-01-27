import sys

sys.stdin = open("D:\Projects\AA\BOJ\9177\input.txt", "r")
input = sys.stdin.readline

N = int(input().rstrip())
a = b = c = ""
dp = []


def makeString(aPos, bPos, cPos):
    if dp[aPos][bPos] != -1:
        print("test")
        return dp[aPos][bPos]

    if aPos == len(a):
        return b[bPos:] == c[cPos:]
    elif bPos == len(b):
        return a[aPos:] == c[cPos:]

    dp[aPos][bPos] = 0

    if a[aPos] == c[cPos]:
        dp[aPos][bPos] = makeString(aPos+1, bPos, cPos+1)
    if b[bPos] == c[cPos]:
        dp[aPos][bPos] = dp[aPos][bPos] or makeString(aPos, bPos+1, cPos+1)
    return dp[aPos][bPos]


for i in range(1, N+1):
    a, b, c = input().rstrip().split()
    dp = [[-1 for _ in range(300)] for __ in range(300)]
    print(f'Data set {str(i)}: ', end="")
    if makeString(0, 0, 0) == 1:
        print("yes")
    else:
        print("no")
