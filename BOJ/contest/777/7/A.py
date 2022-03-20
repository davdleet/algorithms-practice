
import sys

sys.stdin = open('D:\Projects\AA\BOJ\contest\\777\\7\input.txt')
input = sys.stdin.readline

N = int(input().rstrip())

arr = list(map(int, input().rstrip().split()))
d = {}


def initialize():
    global d, arr
    d = {}
    for i in range(N):
        try:
            t = d[arr[i]]
            d[arr[i]] += 1
        except:
            d[arr[i]] = 1


ans = -1

first = 0
last = 0


def search(num, length):
    cnt = 0
    global arr, ans, last, first, d
    while cnt < N:
        if length == len(arr):
            last = num
            if abs(last - first) == 1:
                ans = 1
            return
        found = 0
        try:
            v = d[num+1]
            if not v:
                raise Exception
            found = num+1
            d[num+1] -= 1
        except:
            # not found
            try:
                v = d[num-1]
                if not v:
                    raise Exception
                found = num - 1
                d[num-1] -= 1
            except:
                return
        if found:
            num = found
            length = length + 1


initialize()
keys = d.keys()
for item in keys:
    initialize()
    if ans != -1:
        break
    first = item
    d[item] -= 1
    search(item, 1)

print(ans)
