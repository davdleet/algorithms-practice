import sys

sys.stdin = open(
    "/Users/sungwonlee/Documents/Projects/algorithms-practice/BOJ/11726/input.txt", 'r')

input = sys.stdin.readline

N = int(input().rstrip())

if N < 4:
    print(N)
    exit()

ways_arr = [0, 1, 2, 3]


def ways(num):
    return ways_arr[num-1] + ways_arr[num-2]


for i in range(4, N+1):
    ways_arr.append(ways(i))
print(ways_arr[-1] % 10007)
