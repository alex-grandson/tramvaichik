#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct {
    bool operator()(string  a, string  b) const { return a + b > b + a; }
} sorting;

int main()
{
    vector<string> vct;
    string input;
    while (cin >> input) {
        vct.push_back(input);
    }
    sort(vct.begin(), vct.end(), sorting);
    for (auto & i : vct){
        cout << i;
    }
    cout <<  endl;
    return 0;
}
