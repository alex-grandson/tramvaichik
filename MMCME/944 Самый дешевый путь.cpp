// Самый дешевый путь
// https://informatics.msk.ru/mod/statements/view3.php?id=656&chapterid=944#1
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d ", &n, &m);
    vector< vector<int> > a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d ", &a[i][j]);

    for (int i = 1; i < n; i++)
        a[i][0] = a[i - 1][0] + a[i][0];
    for (int j = 1; j < m; j++)
        a[0][j] = a[0][j - 1] + a[0][j];

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            a[i][j] = min(a[i - 1][j], a[i][j - 1]) + a[i][j];

    printf("%d", a[n - 1][m - 1]);
    return 0;
}