import sys

sys.stdin = open("D:\Projects\AA\BOJ\\6064\input.txt")
input = sys.stdin.readline


T = int(input().rstrip())


def LCM(x, y):
    num = x
    while True:
        if num % y == 0:
            return num
        num = num + x


for i in range(T):
    M, N, X, Y = map(int, input().rstrip().split())
    last = LCM(M, N)
    if M == X and N == Y:
        print(last)
        continue
    x = 1
    y = 1
    year = 1
    ans = 0
    x = X
    year = year + X-1
    y = y+X-1
    y = y % N
    if y == 0:
        y = N
    while True:
        if year < last and y == Y:
            ans = year
            break
        elif year >= last:
            ans = -1
            break
        year = year + M
        y = (y + M) % N
        if y == 0:
            y = N
    print(ans)
