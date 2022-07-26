import sys

sys.stdin = open("D:\Projects\AA\BOJ\\1065\input.txt")
input = sys.stdin.readline

N = int(input().rstrip())


cnt = 0
for i in range(1, N+1):
    temp_s = str(i)
    arr = list(temp_s)
    arr = list(map(int, arr))
    if len(arr) == 1:
        cnt += 1
        continue
    i_diff = arr[1] - arr[0]
    last = 1
    abort = False
    for j in range(2, len(arr)):
        t_diff = arr[j] - arr[last]
        if i_diff != t_diff:
            abort = True
            break
        else:
            last = j
    if abort:
        continue
    cnt += 1

print(cnt)
