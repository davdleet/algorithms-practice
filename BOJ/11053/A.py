import sys

sys.stdin = open(
    "/Users/sungwonlee/Documents/Projects/algorithms-practice/BOJ/11053/input.txt", 'r')

input = sys.stdin.readline

N = int(input().rstrip())
A = input().rstrip().split()
arr = [int(A[i]) for i in range(len(A))]

cnts = [-1 for i in range(len(arr))]
cnts[0] = 1
max_cnt = 1
for i in range(1, len(arr)):
    current_max_cnt = 0
    for j in range(i):
        if arr[j] < arr[i] and cnts[j] > current_max_cnt:
            current_max_cnt = cnts[j]
    cnts[i] = current_max_cnt + 1
    if current_max_cnt+1 > max_cnt:
        max_cnt = current_max_cnt+1
print(max_cnt)
