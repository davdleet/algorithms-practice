import sys
sys.stdin = open("D:\Projects\AA\BOJ\contest\\777\\10\sample\\01.in")


def calc(v, N):
    ans = [0 for i in range(N)]
    ans[0] = 1

    for x in range(1, N):
        for y in range(0, x):
            m = 1000000000000000000  # (1e18)
            for z in range(y, x+1):
                m = min(m, v[z])

            ans[x] = ans[x] + ans[y] * m
            ans[x] = ans[x] % 1000000007  # (1e9 + 7)
    return ans


N = int(input())
v = list(map(int, input().split()))
ans = calc(v, N)

if type(ans) != list:
    print("wrong type")
else:
    for x in ans:
        print(x)
