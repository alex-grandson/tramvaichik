#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int sizeJ=0, sizeI=0;
    scanf("%d %d", &sizeJ, &sizeI);
    vector< vector<char> > a(sizeI, vector<char>(sizeJ));
    for (int i=0; i<sizeI; i++){
        for (int j=0; j<sizeJ; j++){
            scanf(" %c", &a[i][j]);
        }
    }
    vector< vector<char> > b(sizeI, vector<char>(sizeJ));
    for (int i=0; i<sizeI; i++){
        for (int j=0; j<sizeJ; j++) {
            scanf(" %c", &b[i][j]);
        }
    }
    vector< vector<char> > c(1 + '1', vector<char>(1 + '1'));
    scanf(" %c %c %c %c", &c['0']['0'], &c['0']['1'], &c['1']['0'], &c['1']['1']);
    for (int i=0; i<sizeI; i++) {
        for (int j=0; j<sizeJ; j++) {
            printf("%c", c[a[i][j]][b[i][j]]);
        }
        printf("\n");
    }
    return 0;
}
