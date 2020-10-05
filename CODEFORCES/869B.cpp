// B. Вечное бессмертие
// http://codeforces.com/problemset/problem/869/B

#include <iostream>
using namespace std;

unsigned long long int a, b;

long long fact(int a){
    if (a > 1) {
    int ans = 1;
    for (int i = 2; i <= a; i++) {
        ans *= i;
    }
    return ans;
    } else
    	return 1;
}

int main()
{
    cin >> a >> b;
    unsigned int ans = 1;
    if (b - a >= 10) cout << "0"; else {
        for (long long int i = a + 1; i <= b; i++)
            ans = (ans * (i % 10)) % 10;
        cout << ans;
    }
    return 0;
}