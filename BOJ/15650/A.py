import sys

sys.stdin = open('D:\Projects\AA\BOJ\\15650\input.txt', 'r')
input = sys.stdin.readline

N, M = map(int, input().rstrip().split())

arr = [i for i in range(1, N+1)]
ans = [False] * (N + 1)


def solve(num, cnt):
    if cnt == M:
        for i in range(0, len(ans)):
            if ans[i]:
                print(i+1, end=' ')
        print()
    elif num >= N:
        None
    else:
        ans[num] = True
        solve(num + 1, cnt+1)
        ans[num] = False
        solve(num+1, cnt)


solve(0, 0)
