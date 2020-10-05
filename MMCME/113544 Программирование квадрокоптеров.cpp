// https://informatics.mccme.ru/mod/statements/view3.php?chapterid=113544#1
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    string ans(n, '?');
    stack<int> stack;
    for (int i = 1; i <= n; i++){
        if (stack.empty()){
            stack.push(i);
        } else {
            printf("? %d %d\n", stack.top(), i);
            fflush(stdout);
            char buffer[3 + 1];
            scanf("%3s", &buffer);
            string yn(buffer);
            if (yn == "Yes") {
                ans[stack.top() - 1] = '(';
                ans[i - 1] = ')';
                stack.pop();
            } else {
                stack.push(i);
            }
        }
    }
    printf("! %s\n", ans.c_str());
    return 0;
}