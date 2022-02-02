import sys

sys.stdin = open("D:\Projects\AA\BOJ\\13305\input.txt", "r")
input = sys.stdin.readline

N = int(input().rstrip())

D = []
P = []
sorted_P = []

D = list(map(int, input().rstrip().split()))
P = list(map(int, input().rstrip().split()))

current_city = 0
next_idx = 0
fuel = 0
money_used = 0
while current_city != N-1:
    current_oil = P[current_city]
    current_dis = D[current_city]
    count = 1
    if current_city == next_idx:
        next_idx += 1
        while P[current_city] <= P[next_idx]:
            count += 1
            next_idx += 1
            if next_idx == N-1:
                break
        for i in range(current_city, current_city + count):
            if i == N-1:
                break
            money_used = money_used + current_oil * D[i]
    current_city = current_city + 1
print(money_used)
