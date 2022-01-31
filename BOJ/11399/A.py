import sys

sys.stdin = open("D:\Projects\AA\BOJ\\11399\input.txt", "r")
input = sys.stdin.readline

N = int(input().rstrip())
arr = []
arr = list(map(int, input().rstrip().split()))
arr.sort()
sum = arr[0]
ans = sum
for i in range(1, len(arr)):
    ans = ans + sum + arr[i]
    sum = sum + arr[i]
print(ans)
