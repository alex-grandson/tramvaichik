// Клавиатура - 2
// http://acmp.ru/index.asp?main=task&id_task=534
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	map<int, int> m;
	for (int i=0; i<n; i++)
	{
		int x;
		scanf("%d", &x);
		m[i+1]=x;
	}

	int k;
	scanf("%d", &k);
	for (int i=0; i<k; i++)
	{
		int x;
		scanf("%d", &x);
		m[x]--;
		/*
		printf("\n");
		for (int i=0; i<n; i++)
		{
			printf("%d ", m[i+1]);
		}
		printf("\n");
		*/
	}
	for (int i=0; i<n; i++)
	{
		if (m[i+1]<0) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
