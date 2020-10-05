// 612 Выражения
// https://informatics.msk.ru/mod/statements/view3.php?id=634&chapterid=612#1
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, s;
    scanf("%d %d", &n, &s);
    vector<unsigned int> a(n, 0);
    for (int i = 0; i < n; i++)
        scanf(" %d", &a[i]);
    // Если в цикле написани вместо 1 << (n - 1) - pow(2, n - 1), что по сути одно и то же - не пройдет по времени
    // Функция pow слишком медленная
    for (int i = 0; i < 1 << (n - 1); i++) {
        int temp = i;
        int sum = a[0];
        for (int times = 0; times < n - 1; times++) {
            if (temp & 1 == 1)
                sum += a[times + 1];
            else
                sum -= a[times + 1];
            temp = temp >> 1;
        }
        if (sum == s) {
            temp = i;
            printf("%d", a[0]);
            for (int times = 0; times < n - 1; times++) {
                if (temp & 1 == 1)
                    printf("+");
                else
                    printf("-");
                printf("%d", a[times + 1]);
                temp = temp >> 1;
            }
            printf("=%d", s);
            return 0;
        }
    }
    printf("No solution");
    return 0;
}