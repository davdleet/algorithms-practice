import sys

sys.stdin = open("D:\Projects\AA\study-book\\198\input.txt")
input = sys.stdin.readline

N = int(input().rstrip())

arr = list(map(int, input().rstrip().split()))
arr.sort()

M = int(input().rstrip())

targets = list(map(int, input().rstrip().split()))


def binsearch(start, end, find):
    while(1):
        if start > end:
            return -1
        mid = (start+end)//2
        if find == arr[mid]:
            return mid
        elif find > arr[mid]:
            start = mid+1
        else:
            end = mid-1


for target in targets:
    ans = binsearch(0, len(arr)-1, target)
    if ans != -1:
        print('yes', end=' ')
    else:
        print('no', end=' ')
