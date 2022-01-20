import sys


with open("/Users/sungwonlee/Documents/Projects/algorithms-practice/BOJ/8892/input.txt", "r") as f:
    tc = int(input())
    for i in range(0, tc):
        cases = int(input())
        arr = []
        continue_flag = False
        for i in range(0, cases):
            s = input().rstrip()
            arr.append(s)
        for i in range(0, len(arr)):
            current_str = arr[i]
            break_flag = False
            for j in range(0, len(arr)):
                if(i == j):
                    continue
                combined = current_str + arr[j]
                first = None
                second = None
                if(len(combined) % 2 == 0):
                    first = combined[0:int(len(combined)/2)]
                    second = combined[len(combined) -
                                      1:int(len(combined)/2)-1:-1]
                else:
                    middle = int(len(combined) / 2)
                    first = combined[0:middle]
                    second = combined[len(combined) - 1:middle:-1]
                # print(f'first : {first}')
                # print(f'second : {second}')
                if (first != None) and first == second:
                    print(combined)
                    continue_flag = True
                    break_flag = True
                    break
            if(break_flag):
                break
        if continue_flag:
            continue
        print(0)
