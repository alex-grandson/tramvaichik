// Consecutive strings
// https://www.codewars.com/kata/56a5d994ac971f1ac500003e/cpp
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

class LongestConsec {
public:
    static string longestConsec(vector<string> &strarr, int k) {
        int size = (int)strarr.size();
        if (size == 0 || k > size || k < 1) return "";

        string res = "";
        vector<int> lens(size, 0);
        lens[0] = strarr[0].length();
        for (int i = 1; i < k; i++)
            lens[i] = lens[i - 1] + strarr[i].length();
        for (int i = k; i < size; i++)
            lens[i] = lens[i - 1] + strarr[i].length() - strarr[i - k].length();
        int m = lens[k - 1];
        int n = k - 1;
        for (int i = k; i < size; i++)
            if (lens[i] > m) {
                m = lens[i];
                n = i;
            }

        for (int i = n; i > n - k; i -= 1)
            res = strarr[i] + res;

        return res;
    }
};


int main() {
    vector<string> arr = {"ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx", "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh"};
    int k = 1;
    cout << LongestConsec::longestConsec(arr, k) << endl;
    return 0;
}

/* Other solutions:

 // 1
#include <functional>
#include <numeric>
#include <string>
#include <vector>

class LongestConsec {
public:
    static std::string longestConsec(const std::vector<std::string>& strings, int k) {
      k = std::max(k, 0);
      std::string longest;
      for (size_t i = k; i <= strings.size(); i += 1) {
        auto begin = std::next(strings.begin(), i - k);
        auto end = std::next(begin, k);
        std::string s = std::accumulate(begin, end, std::string());
        if (s.length() > longest.length()) {
          longest = s;
        }
      }
      return longest;
    }
};

// 2

 #include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class LongestConsec
{
public:
    static std::string longestConsec(std::vector<std::string> &strarr, int k);
private:
    // custom acumulator for summing up string sizes
    static int acumStringSize(int acum, string str);

};

std::string LongestConsec::longestConsec(std::vector<std::string> &strarr, int k)
{
  // first check all special conditions
  if (strarr.size() == 0 || k > strarr.size() || k <= 0) { return ""; }

  // sizes array contain size of each sequence of k strings
  // in the given string array.
  // index of each sum corresponds to beginning of each sequence in the strings array
  vector<int> sizes;

  // Calculating sizes of all possible sequences
  // Off-by-one correction included by magical +1 :)
  for (int i = 0; i < strarr.size() - k + 1; ++i)
  {
      int sum = accumulate(strarr.begin() + i, strarr.begin() + i + k, 0, LongestConsec::acumStringSize);
      sizes.push_back( sum );
  }

  // max_element does just what we want: returns first occurance of max element
  int index = max_element(sizes.begin(), sizes.end()) - sizes.begin();

  // concatenating strings by accumulator
  return accumulate(strarr.begin() + index, strarr.begin() + index + k, string(""));
}

int LongestConsec::acumStringSize(int total, string str)
{
    return total + str.size();
}

 */