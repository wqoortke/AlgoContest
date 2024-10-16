#include <iostream>

class Fraqtion
{
private:
    long long a;
    long long b;
    long long gcd(int a, int b);
public:
    Fraqtion(long long a, long long b): a(a), b(b){}
    Fraqtion(){}
    void printFraq()
    {
        long long buff = gcd(a, b);
        std::cout << a/buff << ' ' << b/buff << std::endl;
    }
    bool operator<(Fraqtion* other) {
        return this->a * other->b < this->b * other->a;
    };
};

void swap(Fraqtion* a, Fraqtion* b)
{
    Fraqtion buff = *a;
    *a = *b;
    *b = buff;
}
void heapify(Fraqtion* arr, int ind, int length)
{
    int maxx = ind;
    int left = ind*2+1, right = ind*2+2;

    if (left < length && arr[maxx].operator<(&arr[left])){maxx = left;}
    if (right < length && arr[maxx].operator<(&arr[right])){maxx = right;}

    if (maxx != ind)
    {
        swap(&arr[ind], &arr[maxx]);
        heapify(arr, maxx, length);
    }
}

int main()
{
    int n, q;
    std::cin >> n >> q;
    long long nom[n], den[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> nom[i];
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> den[i];
    }
    
    Fraqtion l[n*n];
    int counter = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            l[counter++] = Fraqtion(nom[i], den[j]);
        }
    }

    for (int i = n*n/2; i > -1; --i)
    {
        heapify(l, i, n*n);
    }
    for (int i = 1; i < n*n; ++i)
    {
        swap(l, l+n*n-i);
        heapify(l, 0, n*n - i);
    }
    for (int i = 0; i < q; ++i)
    {
        int buff;
        std::cin >> buff;
        l[--buff].printFraq();
    }
    return 0;
}


long long Fraqtion::gcd(int a, int b)
{
    if (a == 0){return b;}
    if (b == 0 || a == b){return a;}
    if (a > b){return gcd(a - b, b);}

    return gcd(a, b - a);
}

