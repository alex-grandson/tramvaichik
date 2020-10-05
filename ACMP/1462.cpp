// Силовые поля
// http://acmp.ru/asp/do/index.asp?main=task&id_course=3&id_section=24&id_topic=181&id_problem=1192
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Rect
{
	int x;
	int y;
};

int main()
{
	int n, need;
	scanf("%d %d", &n, &need);
	vector<Rect> rects(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &rects[i].x, &rects[i].y);
	
	sort(rects.begin(), rects.end(), [](const Rect &left, const Rect &right)
	{
		return left.y > right.y;
		// Сортируем по убыванию Y-координаты
	});

	long long maxS = 0;
	priority_queue< int, vector<int>, greater<int> > pq; // Содержит X-координаты
	// Здесь используетя greater из <functional> для "обращения порядка".
	// По умолчанию pq.top() выдает максимальный элемент (а параметр стандартный less), но теперь это будет минимальный элемент очереди
	for (const Rect &r : rects)
	{
		pq.push(r.x);
		if (pq.size() > need)
			pq.pop();

		if (pq.size() == need)
			maxS = max(maxS, 1LL * r.y * pq.top());
	}

	printf("%lld", maxS);
	return 0;
}