import sys

sys.stdin = open("D:\Projects\AA\BOJ\\1992\input.txt")
input = sys.stdin.readline
arr = []


def divide(size, x, y):

    if size == 1:
        state = 0
        if int(arr[x][y]) == 0:
            state = 2
        else:
            state = 1
        return (arr[x][y], state)
    else:
        a = divide(int(size/2), x, y)
        c = divide(int(size/2), x, y+int(size/2))
        b = divide(int(size/2), x + int(size/2), y)
        d = divide(int(size/2), x + int(size/2), y+int(size/2))
        state = 0
        s = a[0]+c[0]+b[0]+d[0]
        all_one = False
        all_zero = False
        if a[1] == 1 and b[1] == 1 and c[1] == 1 and d[1] == 1:
            state = 1
            all_one = True
        elif a[1] == 2 and b[1] == 2 and c[1] == 2 and d[1] == 2:
            state = 2
            all_zero = True
        if all_zero:
            s = '0'
        elif all_one:
            s = '1'
        else:
            s = '(' + s + ')'
        return(s, state)


N = int(input().rstrip())
for i in range(N):
    line = list(input().rstrip())
    arr.append(line)

print(divide(N, 0, 0)[0])
