import sys

sys.stdin = open("D:\Projects\AA\study-book\\182\input.txt")
input = sys.stdin.readline

N, K = map(int, input().rstrip().split())

A = list(map(int, input().rstrip().split()))

B = list(map(int, input().rstrip().split()))

A.sort()
B.sort()

for i in range(K):
    A[i], B[-i] = B[-i], A[i]

print(sum(A))
