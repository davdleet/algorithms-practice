import sys

sys.stdin = open("D:\Projects\AA\BOJ\\1780\input.txt")
input = sys.stdin.readline

N = int(input().rstrip())

arr = []

for i in range(N):
    temp = list(map(int, input().rstrip().split()))
    arr.append(temp)


def divide(x, y, size):
    if size == 1:
        num = arr[x][y]
        result = []
        if num == 1:
            result = [0, 0, 1, True]
        elif num == -1:
            result = [1, 0, 0, True]
        else:
            result = [0, 1, 0, True]
        return result
    else:
        result = [0, 0, 0, True]
        smaller_size = size//3
        vals = 0
        first = divide(x, y, smaller_size)
        for i in range(3):
            if first[i]:
                vals += 1
        if vals != 1:
            result[3] = False
        for i in range(3):
            for j in range(3):
                temp = divide(x+i*smaller_size, y+j *
                              smaller_size, smaller_size)
                if temp != first:
                    result[3] = False
                for k in range(3):
                    result[k] = result[k] + temp[k]
        if result[3]:
            result = first
        return result


ans = divide(0, 0, N)

for i in range(3):
    print(ans[i])
