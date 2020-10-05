// 616 1F. Покер
// https://informatics.msk.ru/mod/statements/view3.php?id=634&chapterid=616#1
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    const int countOfCards = 5;
    const int typesOfCards = 13;
    vector<int> a(typesOfCards + 1, 0);
    bool Impossible = false;
    bool FouOfKind = false;
    bool FullHouse = false;
    bool Straight = false;
    bool ThreeOfKind = false;
    bool TwoPairs = false;
    bool OnePair = false;

    for (int i = 0; i < countOfCards; i++) {
        int t = 0;
        scanf("%d", &t);
        a[t] += 1;
    }
    for (int i = 0; i <= typesOfCards; i++) {
        if (a[i] == 2)
            if (OnePair) TwoPairs = true;
            else OnePair = true;
        if (a[i] == 3)
            ThreeOfKind = true;
        if (ThreeOfKind && OnePair)
            FullHouse = true;
        if (a[i] == 4)
            FouOfKind = true;
        if (a[i] == 5)
            Impossible = true;
    }
    for (int i = 5; i <= typesOfCards; i++)
        if (a[i - 4] * a[i - 3] * a[i - 2] * a[i - 1] * a[i] == 1)
            Straight = true;

    if (Impossible) printf("Impossible");
    else if (FouOfKind) printf("Four of a Kind");
    else if (FullHouse) printf("Full House");
    else if (Straight) printf("Straight");
    else if (ThreeOfKind) printf("Three of a Kind");
    else if (TwoPairs) printf("Two Pairs");
    else if (OnePair) printf("One Pair");
    else printf("Nothing");
    return 0;
}