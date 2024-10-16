import heapq

def calcul(arr):
    sum = 0
    while len(arr) >= 2:
        a = heapq.heappop(arr)
        b = heapq.heappop(arr)
        sum += (a + b) * 0.05
        heapq.heappush(arr, a + b)
    return sum

n = int(input())
arr = [int(i) for i in input().split()]
heapq.heapify(arr)
result = calcul(arr)
print(f'{result:.2f}')
