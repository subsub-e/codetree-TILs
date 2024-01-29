m = int(input())

a, b = map(int, input().split())

def binarySearch(target):
    l = 1
    r = m 
    count = 0
    while l <= r:
        count += 1

        mid = (l + r) // 2
        
        if mid  == target:
            return count 
        elif mid  > target:
            r = mid - 1
        else:
            l = mid + 1
    return -1
minAns = 10000000000
maxAns = -1000000000
for target in range(a, b + 1):

    count = binarySearch(target)

    minAns = min(minAns, count)
    maxAns = max(maxAns, count)
print(minAns, maxAns)