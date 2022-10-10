import sys
sys.stdin = open("D:\Projects\AA\BOJ\\14501\input.txt")
input = sys.stdin.readline
N = int(input().rstrip())

jobs = []
jobs.append(0)
for i in range(N):
    line = list(map(int, input().rstrip().split()))
    duration = line[0]
    pay = line[1]
    jobs.append((duration, pay))


def bruteforce(day, money):
    global N
    if day == N+1:
        return money
    else:
        c_duration = jobs[day][0]
        c_pay = jobs[day][1]
        ans = money
        if day + c_duration <= N+1:
            ans = max(ans, bruteforce(day+c_duration, money + c_pay))
        ans = max(ans, bruteforce(day+1, money))
        return ans


print(bruteforce(1, 0))
