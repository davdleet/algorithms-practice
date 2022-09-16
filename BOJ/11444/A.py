import sys

sys.stdin = open(
    "/Users/sungwonlee/Documents/Projects/algorithms-practice/BOJ/11444/input.txt")
input = sys.stdin.readline

N = int(input().rstrip())
g1 = (1 + 5 ** 0.5) / 2
g2 = (-1/g1)
ans = (((g1 ** N) - (-g1 ** -N)) / (5 ** 0.5)) % 1000000007
print(354224848179261915075 % 1000000007)
print(int(ans))
