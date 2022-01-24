import sys

sys.stdin = open(
    "/Users/sungwonlee/Documents/Projects/algorithms-practice/BOJ/11055/input.txt", 'r')

input = sys.stdin.readline

N = int(input().rstrip())
A = input().rstrip().split()
arr = [int(A[i]) for i in range(len(A))]
sum_arr = [0] * len(A)
max_sum = 0
sum_arr[0] = arr[0]
for i in range(N):
    max_sum_temp = 0
    for j in range(0, i):
        if arr[i] > arr[j]:
            if sum_arr[j] > max_sum_temp:
                max_sum_temp = sum_arr[j]
    sum_arr[i] = max_sum_temp + arr[i]
    if(sum_arr[i] > max_sum):
        max_sum = sum_arr[i]

print(max_sum)
