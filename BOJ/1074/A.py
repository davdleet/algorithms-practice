import sys

sys.stdin = open("D:\Projects\AA\BOJ\\1074\input.txt")
input = sys.stdin.readline

N, r, c = map(int, input().rstrip().split())

size = 2 ** N
ans = 0


def search(s, x, y):
    global ans
    # base case
    if x == r and y == c:
        print(ans)
        sys.exit(0)
    # within four quadrants
    if (r >= x and r < x + s) and (c >= y and c < y+s):
        search(s//2, x, y)
        search(s//2, x, y+s//2)
        search(s//2, x+s//2, y)
        search(s//2, x+s//2, y+s//2)
    # if not, add size to answer
    else:
        ans = ans + s**2


search(size, 0, 0)
