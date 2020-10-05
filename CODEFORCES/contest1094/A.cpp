#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=2; i<=n/3+1; i++)
        if ((i-1)*3==n)
        {
            printf("%d %d %d", i-2, i-1, i);
            return 0;
        }
    printf("-1");
    return 0;
}
