#include <cstdio>
using namespace std;

int main() {
    int n = 0;
    int len = 0;
    int lenMax = 0;
    int index[2] = {0};
    int indexMax[2] = {0};
    scanf("%d ", &n);
    int t[3] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d ", &t[i % 3]);
        len++;
        if (t[0] == t[1] && t[1] == t[2]) {
            if (lenMax < len - 1) {
                lenMax = len - 1;
                indexMax[0] = index[0];
                indexMax[1] = i - 1;
            }
            index[0] = i - 1;
            len = 2;
        }
        if (i == n - 1 && len > lenMax) {
            indexMax[0] = index[0];
            indexMax[1] = i;
        }
    }
    printf("%d %d", indexMax[0] + 1, indexMax[1] + 1);
    return 0;
}