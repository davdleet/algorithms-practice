import sys

sys.stdin = open("D:\Projects\AA\BOJ\\16953\input.txt")
input = sys.stdin.readline

A, B = map(int, input().rstrip().split())

ans = 10 ** 9
found = False


def DFS(num, cnt):
    global ans
    global found
    if num > B:
        return
    elif num == B:
        if cnt < ans:
            found = True
            ans = cnt + 1

    else:
        n1 = num << 1
        DFS(n1, cnt+1)
        n2 = int(str(num) + '1')
        DFS(n2, cnt+1)


DFS(A, 0)


if not found:
    ans = -1
print(ans)
