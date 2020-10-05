// Игра в Пьяницу. https://informatics.msk.ru/mod/statements/view3.php?id=206&chapterid=50
#include <cstdio>
#include <deque>
using namespace std;

int main()
{
    deque<char> a(5);
    scanf(" %c %c %c %c %c", &a[0], &a[1], &a[2], &a[3], &a[4]);
    deque<char> b(5);
    scanf(" %c %c %c %c %c", &b[0], &b[1], &b[2], &b[3], &b[4]);
    int k=0;
    while (!a.empty() && !b.empty() && k<1000000) {
        if (a.front()=='9' && b.front()=='0') {
            b.push_back(a.front());
            b.push_back(b.front());
            a.pop_front();
            b.pop_front();
        } else if (a.front()=='0' && b.front()=='9') {
            a.push_back(a.front());
            a.push_back(b.front());
            a.pop_front();
            b.pop_front();
        } else if (a.front() < b.front()) {
            b.push_back(a.front());
            b.push_back(b.front());
            a.pop_front();
            b.pop_front();
        } else if (a.front() > b.front()) {
            a.push_back(a.front());
            a.push_back(b.front());
            a.pop_front();
            b.pop_front();
        }
        k++;
    }
    if (k<1000000) {
        if (a.empty()) printf("second %d", k);
        else printf("first %d", k);
    } else {
        printf("botva");
    }

    return 0;
}
