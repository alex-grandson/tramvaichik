// A. Золотая тарелка
// https://codeforces.com/contest/1031/problem/A

#include <cstdio>

using namespace std;

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int sum=0;
    for (int i=0; i<k; i++)
        sum+=(2*((n-4*i)+(m-4*i))-4);
    printf("%d", sum);
    return 0;
}