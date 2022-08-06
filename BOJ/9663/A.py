import sys

sys.stdin = open("D:\Projects\AA\BOJ\9663\input.txt")
input = sys.stdin.readline

MAX = 15
N = int(input().rstrip())
cols = [0 for _ in range(MAX+1)]

cnt = 0

# check if a queen can be placed in row y


def check(y):
    for i in range(0, y):
        if (cols[y] == cols[i]) or (cols[i] - i == cols[y] - y or cols[i] + i == cols[y] + y):
            return False
    return True


def bruteforce(size):
    global cnt
    if size == N:
        cnt = cnt + 1
    else:
        # iterate through all columns
        for i in range(N):
            cols[size] = i
            if(check(size)):
                bruteforce(size+1)


bruteforce(0)

print(cnt)
