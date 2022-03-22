import sys

sys.stdin = open("D:\Projects\AA\BOJ\\1107\input.txt")
input = sys.stdin.readline

N = int(input().rstrip())
M = int(input().rstrip())
broken = set(map(int, input().rstrip().split()))

start = 100


ans = abs(N - start)


def search(num):
    return abs(N - num) + len(str(num))


for i in range(0, 1000000):
    str_i = str(i)
    set_i = set(map(int, str(i)))
    if len(set_i & broken) != 0:
        continue
    else:
        result = search(i)
        if result < ans:
            ans = result
print(ans)
