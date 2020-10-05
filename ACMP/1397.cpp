// Космическое поселение
// http://acmp.ru/asp/do/index.asp?main=task&id_course=3&id_section=24&id_topic=164&id_problem=1066
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	long long a, b, w, h, N;
	scanf("%lld %lld %lld %lld %lld", &N, &a, &b, &w, &h);
	long long left = 0;
	long long right = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000 + 1; // 1e18
	// Двоичный поиск по возможным значениям D
	// Максимальное количество итераций = log(N) - В худшем случае log(1e18) ~ 60
	while (left + 1 < right)
	{
		long long mid = (right + left) / 2;
		long long d = mid;

		if ((w / (a + 2 * d)) * (h / (b + 2 * d)) < N &&
			(w / (b + 2 * d)) * (h / (a + 2 * d)) < N) // Учитывая поворот
			right = mid;
		else
			left = mid;
	}

	printf("%lld\n", left);
	return 0;
}


/*
	Фигня нерабочая:
	// (w >= a + 2 * d) && (h >= b + 2 * d)
	for (long long d = 1; d <= min((w - a) / 2, (h - b) / 2) + 1; d++)
	{
		row = w / (a + 2 * d);
		col = h / (b + 2 * d);
		if (row >= 1.0l * N / col)
		{
			//printf("row = %2lld, col = %2lld, d = %2lld\n", row, col, d);
			maxD = max(maxD, d);
		} else break;
		//printf("d = %lld\n", d);

	}
	for (long long d = 1; d <= min((w - b) / 2, (h - a) / 2) + 1; d++)
	{
		row = w / (b + 2 * d);
		col = h / (a + 2 * d);
		if (row >= 1.0l * N / col)
		{
			//printf("row = %2lld, col = %2lld, d = %2lld\n", row, col, d);
			maxD = max(maxD, d);
		} else break;
		//printf("d = %lld\n", d);
	}

	*/