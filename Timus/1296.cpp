// 313293SJ
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n = 0;
    long long ans = 0, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a_i = 0;
        scanf(" %d", &a_i);
        sum += a_i;
        sum = max(sum, 0LL);
        ans = max(ans, sum);
    }
    printf("%lld", ans);
}