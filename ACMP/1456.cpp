// Кампус
// http://acmp.ru/asp/do/index.asp?main=task&id_course=3&id_section=24&id_topic=181&id_problem=1186
#include <cstdio>

using namespace std;

int main()
{
	long long n, k, x, y;
	int q;
	scanf("%lld %lld %lld %lld %d", &n, &k, &x, &y, &q);

	long long roomsPerEntrance = (n/k)*x + (n-n/k)*y;
	long long roomsPerBlock = (k-1)*y + x;
	long long cur;
	//printf("Per Entrance = %lld; Per Block = %lld\n", roomsPerEntrance, roomsPerBlock);
	for (int i = 0; i < q; i++)
	{
		scanf("%lld", &cur);
		cur = cur - 1;
		
		long long numRoom = cur % roomsPerEntrance;
		cur = numRoom;
		long long numBlock = cur / roomsPerBlock;
		long long numLevel = (cur % roomsPerBlock / y) < k-1 ? (cur % roomsPerBlock / y) : k-1;
		//printf("%2lld %2lld %2lld %2lld\n", numRoom, numBlock, numLevel, (numBlock*k + numLevel + 1) % roomsPerEntrance);
		printf("%lld\n", numBlock*k + numLevel + 1);
	}
	return 0;
}
/*

7 3 2 3
4
1 19 20 50

*/