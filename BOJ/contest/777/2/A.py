import sys

sys.stdin = open('D:\Projects\AA\BOJ\contest\\777\\2\input.txt')
input = sys.stdin.readline


T = int(input().rstrip())


N = int(input().rstrip())

for i in range(1, T+1):
    line = input().rstrip()
    print(f"Material Management {i}")

    print('Classification ---- End!')
