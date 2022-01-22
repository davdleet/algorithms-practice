import sys
sys.stdin = open(
    "/Users/sungwonlee/Documents/Projects/algorithms-practice/BOJ/2866/input.txt", "r")
input = sys.stdin.readline

i1 = input()
R = int(i1.split()[0])
C = int(i1.split()[1])
# print(R)
# print(C)
MOD = 2**64
cnt = 0
hash_sum_arr = [[0 for j in range(C)] for i in range(R)]
text_arr = []
for i in range(R):
    text_arr.append(list(input().rstrip()))
for i in range(C):
    x = 27
    hash_sum_arr[R-1][i] = (ord(text_arr[R-1][i]) - ord('a') + 1)
    for j in range(R-2, -1, -1):
        hash_sum_arr[j][i] = hash_sum_arr[j+1][i] + \
            (ord(text_arr[j][i]) - ord('a') + 1) * x
        x = x * 27
        x %= MOD
for i in range(1, R):
    d = {}
    break_flag = False
    for j in range(len(hash_sum_arr[i])):
        try:
            val = d[hash_sum_arr[i][j]]
            break_flag = True
            break
        except:
            d[hash_sum_arr[i][j]] = 1
    if break_flag:
        break
    cnt = cnt + 1
print(cnt)
