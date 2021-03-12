// 313293SJ
#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

int abs (int a) {
    if (a < 0) return -a;
    return a;
}

int main() {
    int ans = INT_MAX;
    int n = 0;
    scanf("%d", &n);
    vector<int> w(n, 0);
    for (int i = 0; i < n; i++) scanf(" %d", &w[i]);
    int end = 1 << n;
    for (int i = 0; i < end; i++) {
        int sum = 0;
        for (int j = 0, t = i; j < n; j++, t = t >> 1) {
            if (t & 1)
                sum += w[j];
            else
                sum -= w[j];
        }
        if (abs(sum) < ans) ans = abs(sum);
    }
    printf("%d", ans);
    return 0;
}
