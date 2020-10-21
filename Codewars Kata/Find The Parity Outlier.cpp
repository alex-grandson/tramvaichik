// Find The Parity Outlier https://www.codewars.com/kata/5526fc09a1bbd946250002dc

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int FindOutlier(vector<int> arr)
{
    int result;
    sort(arr.begin(), arr.end(), [](int &a, int &b) -> bool {
       return (abs(a) % 2) > (abs(b) % 2);
    });
    if ((arr[0] + arr[1]) % 2 == 0) {
        return arr[arr.size() - 1];
    }
    return arr[0];
}

int main() {
    int a[] = {2, 4, 0, 100, 4, 11, 2602, 36};
    vector<int> b;
    for (auto t : a) {
        b.push_back(t);
    }
    cout << FindOutlier(b) << endl;
    return 0;
}
