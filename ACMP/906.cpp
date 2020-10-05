// Функция 2
// http://acmp.ru/index.asp?main=task&id_task=906

/* НАИВНОЕ РЕШЕНИЕ

#include <cstdio>
#include <algorithm>
#include <cassert>
int f(int a, int b, int c)
{
	printf("%d %d %d\n", a, b, c);

	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return f(20, 20, 20);
	if (a < b && b < c)
		return f(a, b, c-1) + f(a, b-1, c-1) - f(a, b-1, c);
	else
		return f(a-1, b, c) + f(a-1, b-1, c) + f(a-1, b, c-1) - f(a-1, b-1, c-1);
}

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("\n%d\n", f(a, b, c));
	return 0;
}
*/

#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;

int main()
{
	long long f[21][21][21];
	for (int a = 0; a <= 20; a++)
		for (int b = 0; b <= 20; b++)
			for (int c = 0; c <= 20; c++){
				if (a == 0 || b == 0 || c == 0)
					f[a][b][c] = 1;
				else f[a][b][c] = 0;
			}
			
	int _a, _b, _c;
	scanf("%d %d %d", &_a, &_b, &_c);

	if (_a <= 0 || _b <= 0 || _c <= 0) {
		printf("1");
		return 0;
	}
	
	if (_a > 20 || _b > 20 || _c > 20) {
		_a = 20;
		_b = 20;
		_c = 20;
	}
	
	for (int a = 1; a <= _a; a++)
		for (int b = 1; b <= _b; b++)
			for (int c = 1; c <= _c; c++) {
				if (c > b && b > a)
					f[a][b][c] = f[a][b][c - 1] + f[a][b - 1][c - 1] - f[a][b - 1][c];
				else
					f[a][b][c] = f[a - 1][b][c] + f[a - 1][b - 1][c] + f[a - 1][b][c - 1] - f[a - 1][b - 1][c - 1];
			}
	printf("%lld", f[_a][_b][_c]);
	return 0;
}