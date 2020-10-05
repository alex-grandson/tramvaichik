// LCS - Longest Common Subsequence
// Наибольшая общая подпоследовательность <-------
// https://informatics.mccme.ru/mod/statements/view3.php?id=766&chapterid=204#1
// Наибольшая общая подпоследовательность с восстановлением ответа
// https://informatics.mccme.ru/mod/statements/view3.php?id=766&chapterid=1790#1

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

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

//    a - числовое значение длины наибольшей общей подпоследовательности в каждой точке
    vector< vector<int> > a(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (x[i] == y[j]) {
                a[i][j] = a[i - 1][j - 1] + 1;
            } else {
                a[i][j] = max(a[i - 1][j], a[i][j - 1]);
            }
        }

    printf("%d", a[n][m]);

    return 0;
}