import sys

sys.stdin = open("D:\Projects\AA\BOJ\\18111\input.txt")
input = sys.stdin.readline

N, M, B = map(int, input().rstrip().split())
inventory = B
min_time = 10**20
ans_height = 0
arr = []
remove = 2
add = 1

for i in range(N):
    line = list(map(int, input().split()))
    arr.append(line)

min = 10**20
max = 0
for i in range(len(arr)):
    for j in range(len(arr[i])):
        a = arr[i][j]
        if a > max:
            max = a
        if a < min:
            min = a


for h in range(min, max+1):
    time = 0
    break_flag = False
    inventory = B
    need = 0
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            current = arr[i][j]
            diff = current - h
            if diff == 0:
                continue
            # current land is higher
            elif diff > 0:
                time = time + (diff*remove)
                inventory = inventory + (abs(diff))
            # current land is lower
            else:
                time = time + (abs(diff)*add)
                inventory -= (abs(diff))
    if inventory < 0:
        continue
    if time < min_time:
        min_time = time
        ans_height = h
    elif time == min_time:
        if h > ans_height:
            ans_height = h
print(min_time, ans_height)
