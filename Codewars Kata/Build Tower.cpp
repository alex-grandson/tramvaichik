// Build Tower
// https://www.codewars.com/kata/576757b1df89ecf5bd00073b/
#include <iostream>
#include <iterator>

#include <vector>
#include <string>


using namespace std;

class Kata
{
public:
    static vector<string> towerBuilder(int nFloors)
    {
        int count = 1 + 2 * (nFloors - 1);
        vector<string> res(nFloors, string(count, ' '));

        for (int i = 0; i < nFloors; i++) {
            int start = (count - 2 * i) / 2;
            for (int j = start; j < start + (1 + 2 * i); j++)
                res[i][j] = '*';
        }
        return res;
    }
};

int main() {
    int n = 10;
    vector<string> s = Kata::towerBuilder(n);
    copy(s.begin(), s.end(), ostream_iterator<string>(cout, "\n"));
    return 0;
}

/* Other solutions:

 // 1

 std::vector<std::string> ret;
      for(int i=0; i<nFloors ; i++)
      {
        ret.push_back(std::string(nFloors-i-1,' ') +
                      std::string((i*2)+1,'*') +
                      std::string(nFloors-i-1,' '));
      }
      return ret;

 // 2

 std::vector<std::string> vec;

        const int length = nFloors * 2 - 1;
        const int middle = nFloors - 1;
        std::string str(length, ' ');

        for (int i = 0; i < nFloors; ++i)
        {
            str[middle - i] = str[middle + i] = '*';
            vec.push_back(str);
        }

        return vec;
 */