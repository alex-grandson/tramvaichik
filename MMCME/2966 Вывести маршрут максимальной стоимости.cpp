// Вывести маршрут максимальрой стоимости
// https://informatics.msk.ru/mod/statements/view3.php?id=656&chapterid=2966#1
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector< vector<int> > a(n, vector<int>(m));
    vector< vector<char> > from(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d ", &a[i][j]);
            from[i][j] = '0';
        }
    }
    string s = "";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j > 0) {
                a[i][j] = a[i][j - 1] + a[i][j];
                from[i][j] = 'R';
            }
            if (i > 0 && j == 0) {
                a[i][j] = a[i - 1][j] + a[i][j];
                from[i][j] = 'D';
            }
            if (i > 0 && j > 0) {
                if (a[i - 1][j] > a[i][j - 1]) {
                    a[i][j] = a[i - 1][j] + a[i][j];
                    from[i][j] = 'D';
                } else {
                    a[i][j] = a[i][j - 1] + a[i][j];
                    from[i][j] = 'R';
                }
            }
        }
    }
    int i = n - 1, j = m - 1;
    while (i != 0 || j != 0) {
        if (from[i][j] == 'R') {
            s = "R " + s;
            if (j > 0) j -= 1;
        }
        if (from[i][j] == 'D') {
            s = "D " + s;
            if (i > 0) i -= 1;
        }
    }
    printf("%d\n%s", a[n - 1][m - 1], s.c_str());
    return 0;
}