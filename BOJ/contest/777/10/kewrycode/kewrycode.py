
def calc(v, N):
    ans = []
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
