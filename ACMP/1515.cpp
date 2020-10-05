// Удаление чисел
// http://acmp.ru/asp/do/index.asp?main=task&id_course=3&id_section=24&id_topic=210&id_problem=1371

#include <cstdio>
using namespace std;

int main()
{
    long long n;
    int k;
    scanf("%lld %d", &n, &k);
    int step=1;
    while (true)
    {
        if (n%k==0)
        {
            printf("%d", step);
            return 0;
        } else
        {
            n-=n/k;
            step++;
        }
        if (n<k)
        {
            printf("0");
            return 0;
        }
    }
}