// A. Чтение книги
// https://codeforces.com/contest/884/problem/A

#include <iostream>
using namespace std;

int n, t, x = 0;
unsigned int a[100], sum;

int main(){
    cin >> n >> t;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum = sum + 86400 - a[i];
        if (t <= sum && x == 0){
            x = i;
            break;
        }
    }
    cout << x + 1;
}