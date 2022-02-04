import sys

sys.stdin = open("D:\Projects\AA\BOJ\\14713\input.txt", )
input = sys.stdin.readline

N = int(input().rstrip())

ptrs = [0] * N
arr = [None] * N
d = {}
c_arr = [None] * N

for i in range(N):
    line = input().rstrip().split()
    for l in line:
        try:
            d[l] == None
            d[l].append(i)
        except:
            d[l] = [i]
    arr[i] = line

words = input().rstrip().split()

for w in words:
    try:
        idx = d[w][0]
        if len(d[w]) == 1:
            del d[w]
        else:
            d[w] = d[w][1:]
        if c_arr[idx] == None:
            c_arr[idx] = []
        c_arr[idx].append(w)
    except:
        print("Impossible")
        exit(0)

for i in range(len(c_arr)):
    if c_arr[i] == arr[i]:
        None
    else:
        print("Impossible")
        exit(0)
print("Possible")
