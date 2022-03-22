import sys
sys.stdin = open('D:\Projects\AA\BOJ\\5430\input.txt')
input = sys.stdin.readline

T = int(input().rstrip())

for i in range(T):

    code = list(input().rstrip())
    N = int(input().rstrip())
    size = N
    line = input().rstrip().replace('[', '')
    line = line.replace(']', '')
    line = line.split(',')
    if '' in line:
        line.remove('')
    arr = list(map(int, line))
    errorFlag = False
    start = 0
    end = len(arr)-1
    step = 1
    for c in code:
        if c == 'R':
            start, end = end, start
            step = step * -1
        elif c == 'D':
            if size == 0:
                print("error")
                errorFlag = True
                break
            else:
                start += step
                size -= 1
    if not errorFlag:
        # print(start, end, step)
        # print(arr)
        print('[', end='')
        for i in range(start, end+step, step):
            print(arr[i], end='')
            if i != end:
                print(',', end='')
        print(']')
