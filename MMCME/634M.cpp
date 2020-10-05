// Скобки
// https://informatics.msk.ru/mod/statements/view3.php?id=634&chapterid=634#1

#include <cstdio>
#include <stack>

using namespace std;

int main() {
    int n;
    scanf("%d ", &n);
    stack<char> stack;
    for (int i = 0; i < n; i++) {
        char c;
        scanf(" %c", &c);
        if (c == '(' || c == '[' || c == '{')
            stack.push(c);
        else
            if (!stack.empty() && (
                (stack.top() == '(' && c == ')') ||
                (stack.top() == '{' && c == '}') ||
                (stack.top() == '[' && c == ']')))
                stack.pop();
            else {
                stack.push(c);
            }
    }
    if (stack.empty())
        printf("Yes");
    else
        printf("No");
    return 0;
}