// Задача №269. Площадь треугольника
// https://informatics.mccme.ru/mod/statements/view3.php?id=1156&chapterid=269#1

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	vector<int> x(3, 0);
	vector<int> y(3, 0);
	for (int i = 0; i < 3; i++)
		scanf("%d %d", &x[i], &y[i]);
	// Bubble Sort - O(n^2)
	// for (int i = 0; i < 3; i++) {
	// 	printf("%d;%d\n", x[i], y[i]);
	// }
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (x[i] < x[j]) {
				int t = x[i];
				x[i] = x[j];
				x[j] = t;
				
				t = y[i];
				y[i] = y[j];
				y[j] = t;
			}
		}
	}
	// printf("\n");
	// for (int i = 0; i < 3; i++) {
	// 	printf("%d;%d\n", x[i], y[i]);
	// }
	int s1 = (y[0] + y[1]) * abs(x[1] - x[0]);
	int s2 = (y[1] + y[2]) * abs(x[2] - x[1]);
	int s3 = (y[0] + y[2]) * abs(x[2] - x[0]);
	int s0 = abs(s1 + s2 - s3);
	printf("%f", (float)s0/2);
	return 0;
}