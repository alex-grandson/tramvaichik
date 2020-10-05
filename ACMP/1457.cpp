// Калькулятор
// http://acmp.ru/asp/do/index.asp?main=task&id_course=3&id_section=24&id_topic=181&id_problem=1187
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
	long long n;
	int a0, b0, c0;
	long long num[64][64][64];
	scanf("%lld %d %d %d", &n, &a0, &b0, &c0);
	
	for (int a = 0; a <= a0; a++)
		for (int b = 0; b <= b0; b++)
			for (int c = 0; c <= c0; c++)
				num[a][b][c] = LLONG_MAX;

	num[a0][b0][c0] = n;

	for (int a = a0; a >= 0; a--)
	{
		for (int b = b0; b >= 0; b--)
		{
			for (int c = c0; c >= 0; c--)
			{
				if (a > 0)
				{
					num[a-1][b][c] = min(num[a-1][b][c], num[a][b][c] / 2);
				}
				if (b > 0)
				{
					num[a][b-1][c] = min(num[a][b-1][c], (num[a][b][c] + 1) / 2);
				}
				if (c > 0)
				{
					num[a][b][c-1] = min(num[a][b][c-1], (num[a][b][c] - 1) / 2);
				}
			}
		}
	}
	printf("%lld", num[0][0][0]);
	return 0;
}