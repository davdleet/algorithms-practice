import sys

sys.stdin = open("D:\Projects\AA\BOJ\\2096\input.txt")
input = sys.stdin.readline

N = int(input().rstrip())
temp = list(map(int, input().rstrip().split()))
arr1 = temp
min_arr1 = temp
if N == 1:
    print(max(arr1), end=" ")
    print(min(min_arr1), end="")
else:
    arr2 = []
    min_arr2 = []
    for i in range(1, N):
        temp = list(map(int, input().rstrip().split()))
        arr2 = temp
        min_arr2 = []
        for j in range(3):
            min_arr2.append(temp[j])
        for j in range(3):
            if j == 0:
                arr2[j] = arr2[j] + max(arr1[:2])
                min_arr2[j] = min_arr2[j] + min(min_arr1[:2])
            elif j == 1:
                arr2[j] = arr2[j] + max(arr1)
                min_arr2[j] = min_arr2[j] + min(min_arr1)
            else:
                arr2[j] = arr2[j] + max(arr1[1:])
                min_arr2[j] = min_arr2[j] + min(min_arr1[1:])
        arr1 = arr2
        min_arr1 = min_arr2
    print(max(arr2), end=" ")
    print(min(min_arr2), end="")
