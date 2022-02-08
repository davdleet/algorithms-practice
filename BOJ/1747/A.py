import sys

sys.stdin = open("D:\Projects\AA\BOJ\\1747\input.txt")
input = sys.stdin.readline


def isPrime(num):
    if num == 1:
        return False
    for i in range(2, int(num**0.5)+1):
        if num % i == 0:
            return False
    return True


def isPalindrome(num):
    num = str(num)
    for i in range(len(num)//2):
        if num[i] != num[-i-1]:
            return False
    return True


N = int(input().rstrip())

ans = N
while(True):
    if isPrime(ans) and isPalindrome(ans):
        break
    ans += 1

print(ans)
