// Split Strings https://www.codewars.com/kata/515de9ae9dcfc28eb6000001/
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;
vector<string> solution(const string &s)
{
    vector<string> ans;
    int len = s.length();
    for (int i = 0; i < len - (len % 2); i += 2) {
        ans.push_back({s[i], s[i+1]});
    }
    if (len % 2) {
        ans.push_back({s.back(), '_'});
    }
    return ans;
}

int main() {
    vector<string> s = solution("abcdef");
    copy(s.begin(), s.end(), ostream_iterator<string>(cout, " "));
    return 0;
}

/* Other solutions:

vector<std::string> solution(const std::string &s) {
    vector <string> res;
    for (int i = 0; i < s.length(); i += 2) res.push_back(s.substr(i, 2));
    if (s.length() % 2) res[res.size() - 1] += "_";
    return res;
}
#include <regex>
vector<std::string> solution(const std::string &s) {
    regex r{".."};
    auto str = s + '_';
    return {sregex_token_iterator(str.begin(), str.end(), r), {}};
}
*.