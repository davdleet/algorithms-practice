import sys

sys.stdin = open("D:\Projects\AA\BOJ\\1802\input.txt")
input = sys.stdin.readline

T = int(input().rstrip())

for i in range(T):
    t = list(map(int, input().rstrip()))
    yes = True
    while(len(t) != 1):
        m = len(t) // 2
        b_flag = False
        for i in range(0, m):
            current = t[i]
            check = t[(len(t) - 1) - i]
            if current == check:
                yes = False
                break
        if b_flag:
            break
        t = t[:m]
    if yes:
        print("YES")
    else:
        print("NO")
