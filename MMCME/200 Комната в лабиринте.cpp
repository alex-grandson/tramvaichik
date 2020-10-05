// Комната в лабиринте	https://informatics.msk.ru/mod/statements/view3.php?id=268&chapterid=200#
#include <cstdio>
#include <vector>
using namespace std;

int f(int &n, vector< vector<char> > &a, int x, int y, int &ans) {
    if (a[x][y] == '.') {
        ans += 1;
        a[x][y] = '+';
    }
    if (y - 1 > 0 && a[x][y - 1] == '.')
        f(n, a, x, y - 1, ans);
    if (y + 1 < n && a[x][y + 1] == '.')
        f(n, a, x, y + 1, ans);
    if (x - 1 > 0 && a[x - 1][y] == '.')
        f(n, a, x - 1, y, ans);
    if (x + 1 < n && a[x + 1][y] == '.')
        f(n, a, x + 1, y, ans);

    return ans;
}
int main() {
    int n;
    scanf("%d", &n);
    vector< vector<char> > room(n, vector<char>(n, '0'));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf(" %c", &room[i][j]);

    int x, y;
    scanf("%d %d", &x, &y);
    int count = 0;
    int ans = f(n, room, x - 1, y - 1, count);
    printf("%d", ans);
    return 0;
}
