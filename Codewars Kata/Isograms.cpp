// Isograms
// https://www.codewars.com/kata/54ba84be607a92aa900000f1/cpp
#include <iostream>
#include <string>

using namespace std;

bool is_isogram(string str) {
    int alphabet[26];
    for (int &i : alphabet) i = 0;
    for (char c : str) {
        int i;
        if (c >= 'A' && c <= 'Z') i = c - 'A';
        if (c >= 'a' && c <= 'z') i = c - 'a';
        alphabet[i] += 1;
        if (alphabet[i] > 1) return false;
    }
    return true;
}

int main() {
    cout << is_isogram("moOse") << endl;
    return 0;
}

/* Other solutions:

#include <set>
#include <algorithm>
using namespace std;

bool is_isogram(string str) {
    if (str.length() == 0) {return true;}
    transform(str.begin(),str.end(),str.begin(),::tolower);
    set <char> iso (str.begin(),str.end());
    if (iso.size() == str.length()) {return true;} else {return false;}
}

 */