// http://acmp.ru/asp/do/index.asp?main=task&id_course=3&id_section=24&id_topic=102&id_problem=522

#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n, m, x;
	scanf("%d %d", &n, &m);
	char buffer[255+1];
	scanf("%255s", &buffer);
	string name = buffer;
	int ans = 0;
	for (int i=0; i<m; i++)
	{
		scanf("%d", &x);
		ans+=x;
	}
	for (int r = 0; r < n-1; r++)
	{
		buffer[255 + 1];
		scanf("%255s", &buffer);
		int sum = 0;
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &x);
			sum += x;
		}
		if (sum < ans)
		{
			ans = sum;
			name = buffer;
		}
	}
	printf("%s", name.c_str());
	return 0;
}