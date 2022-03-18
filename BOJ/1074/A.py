import sys

sys.stdin = open("D:\Projects\AA\BOJ\\1074\input.txt")
input = sys.stdin.readline

N, r, c = map(int, input().rstrip().split())

size = 2 ** N
ans = 0


def search(size, x, y):
    ans = size
    # base case
    if x == r and y == c:

        return ans
    if (r >= x and r < x + size) and (c >= y and c < y+size):
        search(size/2, x, y)
        search(size/2, x+size/2, y)
        search(size/2, x, y+size/2)
        search(size/2, x+size/2, y+size/2)
    else:
        ans += (size * size)


search(size, 0, 0)
print(size)
