import sys
sys.stdin = open("D:\Projects\AA\\foobar\input.txt")
input = sys.stdin.readline


def solution(x):
    # Your code here
    ans = ""
    for c in x:
        if c.islower():
            ans = ans + chr(25 - (ord(c) - ord("a")) + ord('a'))
        else:
            ans = ans + c
    print(ans)


line = input().rstrip()
solution(line)
