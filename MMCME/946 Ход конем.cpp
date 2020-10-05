// Ход конем https://informatics.msk.ru/mod/statements/view3.php?id=656&chapterid=946#1
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector< vector<int> > a(n, vector<int>(m, 0));
    a[0][0] = 1;
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if ((i == 1 && j == 2) || (i == 2 && j == 1))
                a[i][j] = 1;
            else if (i > 1 && j > 1 && (a[i - 1][j - 2] != 0 || a[i - 2][j - 1] != 0))
            {
                a[i][j] = a[i - 1][j - 2] + a[i - 2][j - 1];
            }

    printf("%d", a[n - 1][m - 1]);
    return 0;
}