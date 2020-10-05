// Старая книга
// http://acmp.ru/asp/do/index.asp?main=task&id_course=3&id_section=24&id_topic=210&id_problem=1372

#include <cstdio>
using namespace std;

int main()
{
	long long k, s;
	scanf("%lld %lld", &k, &s);
	long long count = 0;
	long long sum = 0;
	for (long long i = k+1; sum < s; i++)
	{
		sum += i;
		count++;
	}
	if (sum == s)
	{
		printf("%lld", k);
		return 0;
	}
	sum -= k + count;
	count--;
	long long step = (s - sum + (count - 1)) / count;
	printf("%lld", k+step);
	return 0;
}



