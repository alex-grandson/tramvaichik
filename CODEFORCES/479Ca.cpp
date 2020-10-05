// C. Экзамены - некрасивый вариант
// https://codeforces.com/contest/479/problem/C

#include <cstdio>
#include <vector>
using namespace std;
void qsort (vector<int> &a, vector<int> &b, unsigned int st0, unsigned int en0)
{
    unsigned int st=st0;
    unsigned int en=en0;
    auto d=a[en0];
    do
    {
        while (a[st] < d) st++;
        while (a[en] > d) en--;
        if (st<=en)
        {
//            if (a[st]==a[en])
//            {
//                qsort(b, a, st, en);
//            }
            swap(a[st], a[en]);
            swap(b[st], b[en]);
            st++;
            en--;
        }
    } while (st<=en);
    if (en>st0)
        qsort(a, b, st0, en);
    if (st<en0)
        qsort(a, b, st, en0);

}
int main()
{
    unsigned int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<int> b(n);
    for (int i=0; i<n; i++)
        scanf("%d %d", &a[i], &b[i]);

    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
        {
            if (a[i]>a[j])
            {
                swap(a[i],a[j]);
                swap(b[i], b[j]);
            }
            if (i!=j && a[i]==a[j] && b[i]>b[j])
                swap(b[i], b[j]);
        }


    int k=-1;
    for (int i=0; i<n; i++)
        if (k<=b[i]) k=b[i];
        else k=a[i];

    printf("%d", k);
    return 0;
}