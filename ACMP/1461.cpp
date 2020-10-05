// Большой линейный коллайдер
// http://acmp.ru/asp/do/index.asp?main=task&id_course=3&id_section=24&id_topic=181&id_problem=1191
#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long long n, m, x, prev = 0;
	int v, j = 0;
	stack<long long> stack;
	vector<long long> time;
	scanf("%lld", &n);
	for (long long i = 0; i < n; i++)
	{
		scanf("%lld %d", &x, &v);

		if (v == 1)
			stack.push(x);

		if (!stack.empty() && v == -1)
		{
			time.push_back((x - stack.top() + 1) / 2);
			stack.pop();
		}
	}

	sort(time.begin(), time.end());

	scanf("%lld", &m);
	for (long long i = 0; i < m; i++)
	{
		long long curTime;
		scanf("%lld", &curTime);
		while (j < time.size() && time[j] <= curTime)
		{
			prev += 2;
			j++;
		}
		printf("%lld ", n - prev);
	}
	

	return 0;
}
