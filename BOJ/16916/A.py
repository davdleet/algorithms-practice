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

x = 27
target_hash = ord(P[len(P) - 1]) - ord('a') + 1
for i in range(len(P)-2, -1, -1):
    target_hash = target_hash + ((ord(P[i]) - ord('a') + 1) * x)
    if i != 0:
        x = x * 27
        x = x % MOD
x = 27
x1 = 1
p1 = len(S) - 1
p2 = len(S) - 1 - window_size
found = False
current_hash = (ord(S[len(S) - 1]) - ord('a') + 1) * x1
for i in range(len(S) - 2, len(S) - window_size - 1, -1):
    current_hash = current_hash + ((ord(S[i]) - ord('a') + 1) * x)
    if i != (len(S) - window_size):
        x = x * 27
        x = x % MOD
if window_size == 1:
    x = 1
if current_hash == target_hash:
    print(1)
    sys.exit(0)

for i in range(len(S)-window_size-1, -1, -1):
    if current_hash == target_hash:
        found = True
        break
    print(current_hash)
    current_hash = current_hash - \
        ((ord(S[i+window_size]) - ord('a') + 1) * x1)

    current_hash = current_hash / 27
    current_hash = current_hash + ((ord(S[i]) - ord('a') + 1) * x)
    if current_hash == target_hash:
        found = True
        break
if(current_hash == target_hash):
    found = True
if found:
    print(1)
else:
    print(0)
