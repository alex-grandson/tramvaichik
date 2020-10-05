// Квадраты и кубы
// http://acmp.ru/asp/do/index.asp?main=task&id_course=3&id_section=24&id_topic=210&id_problem=1368
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
long long fl(long long x)
{
	long long r = (long long)floor(sqrt(x));
	while (r * r > x)
		r--;
	while ((r+1) * (r+1) <= x)
		r++;
	return r;
}

long long cl(long long x)
{
	long long r = (long long)ceil(sqrt(x));
	while (r * r < x)
		r++;
	while ((r-1) * (r-1) >= x)
		r--;
	return r;
}

int main()
{
	long long a, b, k;
	long long ans = 0;
	scanf("%lld %lld %lld", &a, &b, &k);
	for (long long y = 1; y <= 1000 * 1000; y++)
	{
		long long c = y * y * y;
		if (a <= c && c <= b)
		{
			long long t = fl(min(b, c + k)) - cl(max(a, c - k)) + 1;
			if (t > 0)
				ans += t;
		}
	}
	printf("%lld", ans);
	return 0;
}
