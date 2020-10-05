// LCS - Longest Common Subsequence
// Наибольшая общая подпоследовательность
// https://informatics.mccme.ru/mod/statements/view3.php?id=766&chapterid=204#1
// Наибольшая общая подпоследовательность с восстановлением ответа <--------
// https://informatics.mccme.ru/mod/statements/view3.php?id=766&chapterid=1790#1

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void printAnswer(vector< vector<int> > &from, vector<int> &x, int i, int j) {
    if (i == 0 || j == 0)
        return;
    if (from[i][j] == 11) {
        printAnswer(from, x, i - 1, j - 1);
        printf("%d ", x[i]);
    }
    if (from[i][j] == 1) {
        printAnswer(from, x, i, j - 1);
    }
    if (from[i][j] == 10) {
        printAnswer(from, x, i - 1, j);
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d ", &x[i]);
    scanf("%d", &m);
    vector<int> y(m + 1);
    for (int i = 1; i <= m; i++)
        scanf("%d ", &y[i]);

    vector< vector<int> > a(n + 1, vector<int>(m + 1, 0));
    vector< vector<int> > from(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (x[i] == y[j]) {
                a[i][j] = a[i - 1][j - 1] + 1;
                from[i][j] = 11;
            } else {
//                a[i][j] = max(a[i - 1][j], a[i][j - 1]); - не прокатит
                if (a[i - 1][j] > a[i][j - 1]) {
                    a[i][j] = a[i - 1][j];
                    from[i][j] = 10;
                } else {
                    a[i][j] = a[i][j - 1];
                    from[i][j] = 1;
                }
            }
        }

//    Прямое восстановление ответа с "переворачиванием" подпоследовательности
    vector<int> subs; // - для хранения LCS
    int i = n;
    int j = m;
    while (i > 0 && j > 0) {
        if (from[i][j] == 11) {
            if (a[i][j] != 0)
                subs.push_back(x[i]);
            i -= 1;
            j -= 1;
        }
        if (from[i][j] == 1) {
            j -= 1;
        }
        if (from[i][j] == 10) {
            i -= 1;
        }
    }

    for (int i = (int)subs.size() - 1; i >= 0; i -= 1)
        printf("%d ", subs[i]);
    printf("\n");
//    Рекурсивное восстановление ответа
//    Может не поместиться в оперативную память, если передавать каждый раз 2 больших массива
//    Поэтому нужно передавать не экземляр объекта, а оригинал, причем только один раз - поэтому & в функции важен!
    printAnswer(from, x, n, m);

    return 0;
}

//    a - числовое значение длины наибольшей общей подпоследовательности в каждой точке
//    from - откуда было получено значение (для восстановления ответа)
//      '↑' = 10 - пришли из [i - 1][j]
//      '↖' = 11 - пришли из [i - 1][j - 1]
//      '←' = 01 - пришли из [i][j - 1]