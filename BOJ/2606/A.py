import sys

sys.stdin = open("D:\Projects\AA\BOJ\\2606\input.txt")
input = sys.stdin.readline


N = int(input().rstrip())
M = int(input().rstrip())

v = [[] for _ in range(N+1)]
check = [False for _ in range(N+1)]
for i in range(M):
    v1, v2 = map(int, input().rstrip().split())
    v[v1].append(v2)
    v[v2].append(v1)

count = 0


def dfs(num):
    global count
    if len(v[num]) == 0:
        return
    else:
        for i in range(len(v[num])):
            if not check[v[num][i]]:
                check[v[num][i]] = True
                count += 1
                dfs(v[num][i])
            else:
                None


check[1] = True
dfs(1)
print(count)
