// 1A. Простые числа №611
// https://informatics.msk.ru/mod/statements/view3.php?id=634&chapterid=611#1

#include <cstdio>
#include <cmath>
using namespace std;
bool isPrime(int x) {
    for (int i = 2; i <= ceil(sqrt(x)); i++)
        if (x > i && x % i == 0)
            return false;
    return true;
}
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int count = 0;
    for (int i = a; i <= b; i++) {
        if (isPrime(i)) {
            printf("%d\n", i);
            count += 1;
        }
    }
    if (count == 0)
        printf("Absent");
    return 0;
}