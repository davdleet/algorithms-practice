import sys

sys.stdin = open("D:\Projects\AA\BOJ\\2407\input.txt")
input = sys.stdin.readline


n, m = map(int, input().rstrip().split())

n_fac = 1
for i in range(n, 0, -1):
    n_fac = n_fac * i

m_fac = 1
for i in range(m, 0, -1):
    m_fac = m_fac * i

n_m_fac = 1
for i in range(n-m, 0, -1):
    n_m_fac = n_m_fac * i

ans = n_fac // (m_fac * n_m_fac)
print(ans)
