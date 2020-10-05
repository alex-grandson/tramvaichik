#include <cstdio>
#include <vector>

using namespace std;

void swap (int *f, int *s) {
    int temp = *f;
    *f = *s;
    *s = temp;
}

int main()
{
    int a[6];
    int b[6];
    for (int i=0; i<6; i++) {
        int x, y;
        scanf(" %d %d", &x, &y);
        a[i]=min(x,y);
        b[i]=max(x,y);
    }
    // Sort
    for (int i=0; i<5; i++) {
        for (int j=0; j<5-i; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                swap(b[j], b[j+1]);
            }
        }
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<3-i; j++) {
            if (b[j] > b[j+1]) {
                swap(a[j], a[j+1]);
                swap(b[j], b[j+1]);
            }
        }
    }
    if (
        a[0]==a[1] && a[1]==a[2] && a[2]==a[3] &&
        a[4]==b[0] && a[5]==b[1] && a[4]==a[5] &&
        b[2]==b[3] && b[3]==b[4] && b[4]==b[5]
       ) {
        printf("POSSIBLE");
    } else {
        printf("IMPOSSIBLE");
    }
    return 0;
}
