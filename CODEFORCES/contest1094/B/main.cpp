#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<char> buffer(1000);
    scanf("%1000s", buffer);
    string s = buffer;
    puts(s.c_str());
    return 0;
}
