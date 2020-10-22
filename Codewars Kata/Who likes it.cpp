// Who likes it?
// https://www.codewars.com/kata/5266876b8f4bf2da9b000362
#include <iostream>
#include <iterator>

#include <vector>
#include <string>


using namespace std;

string likes(const vector<string> &names)
{
    switch (names.size()) {
        case 0: return "no one likes this";
        case 1: return names[0] + " likes this";
        case 2: return names[0] + " and " + names[1] + " like this";
        case 3: return names[0] + ", " + names[1] + " and " + names[2] + " like this";
        default: return names[0] + ", " + names[1] + " and " + to_string((int)names.size() - 2) + " others like this";

    }
}

int main() {

    vector<string> s = {"Jacob", "Alex"};
    cout << likes(s) << endl;
    return 0;
}

/* Other solutions:

 // 1


 */