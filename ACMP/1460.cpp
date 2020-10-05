// Автоматизированное управление доставкой
// http://acmp.ru/asp/do/index.asp?main=task&id_course=3&id_section=24&id_topic=181&id_problem=1190

#include <cstdio>
using namespace std;

int main()
{
	long long k, x, y;
	scanf("%lld %lld %lld", &k, &x, &y);
	if (y % x == 0)
		printf("%lld", y);
	else if (k == 1)
		printf("%lld", 1LL * ((y / x + 1) * x));
	else
		printf("%lld", (y / x * (x + k - 1) < y) ? (y / x + 1) * x : y);
		
	return 0;
}