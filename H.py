n, ind = map(int, input().split())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
c = [int(i) for i in input().split()]

def gcd(a,b):
    for i in range(min(a,b), 2, -1):
        if a%i == 0 and b%i == 0:
            return i
    return 1

d = [(x / gcd(x,y),y / gcd(x,y)) for x in a for y in b]


print(d)
