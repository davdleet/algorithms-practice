import sys

sys.stdin = open("D:\Projects\AA\BOJ\\1463\input.txt")
input = sys.stdin.readline

N = int(input().rstrip())

d = {}


def search(num, count):
    if num == 1:
        return count
    else:
        a = 10**9
        b = 10**9
        c = 10**9
        t = 0
        try:
            t = d[num/3]
        except:
            d[t] = 1
            if num % 3 == 0:
                a = search(num / 3, count+1)
        try:
            t = d[num/2]
        except:
            d[t] = 1
            if num % 2 == 0:
                b = search(num / 2, count+1)

        try:
            t = d[num-1]
        except:
            d[t] = 1
            c = search(num - 1, count+1)
        return min(a, b, c)


print(search(N, 0))
