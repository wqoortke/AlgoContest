n = int(input())
array = list(map(int, input().split()))

def merge(l, r):
    i, j = 0, 0
    res = []
    while i < len(l) and j < len(r):
        if (l[i] < r[j]):
            res.append(l[i])
            i += 1
        elif (l[i] >= r[j]):
            res.append(r[j])
            j += 1
    res.extend(l[i:])
    res.extend(r[j:])
    return res

def mergeSort(l: list[int]):
    if len(l) > 1:
        left = mergeSort(l[len(l)//2:])
        right = mergeSort(l[:len(l)//2])
        return merge(left, right)
    return l

print(*mergeSort(array) if n != 0 else "")
