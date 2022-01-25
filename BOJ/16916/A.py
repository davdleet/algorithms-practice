import sys

sys.stdin = open(
    "/Users/sungwonlee/Documents/Projects/algorithms-practice/BOJ/16916/input.txt", "r")
input = sys.stdin.readline


S = list(input().rstrip())
P = list(input().rstrip())

window_size = len(P)
current_hash = 0
target_hash = 0
MOD = 2 ** 64

x = 1
for i in range(len(P)-1, -1, -1):
    target_hash = target_hash + ((ord(P[i]) - ord('a') + 1) * x)
    target_hash = target_hash % MOD
    x *= 27
    x %= MOD
found = False
x = 1
for i in range(len(P)-1, -1, -1):
    current_hash = current_hash + ((ord(S[i]) - ord('a') + 1) * x)
    current_hash = current_hash % MOD
    if i > 0:
        x *= 27
        x %= MOD
if current_hash == target_hash:
    print(1)
    sys.exit(0)

for i in range(len(S) - len(P)):
    current_hash -= (ord(S[i]) - ord('a') + 1)*x
    current_hash = current_hash * 27
    current_hash = current_hash + (ord(S[i+window_size]) - ord('a') + 1)
    current_hash %= MOD
    if current_hash == target_hash:
        found = True
        break
if found:
    print(1)
else:
    print(0)
