// B. Мишка и японские кроссворды
// https://codeforces.com/contest/884/problem/B

#include <iostream>

using namespace std;

unsigned int n, x, a, sum = 0;

int main(){
    cin >> n >> x;
    for (int i = 0; i < n; i++){
        cin >> a;
        sum += a;
    }
    if (sum + n - 1 == x) cout << "YES";
        else cout << "NO";
}