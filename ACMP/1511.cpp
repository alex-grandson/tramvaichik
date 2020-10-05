// Улучшение успеваемости
// http://acmp.ru/asp/do/index.asp?main=task&id_course=3&id_section=24&id_topic=210&id_problem=1367&ins=1#solution

#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    if (3*a+b-c>0) printf("%lld",(3*a+b-c+2)/3);
    else printf("%d", 0);
    return 0;
}