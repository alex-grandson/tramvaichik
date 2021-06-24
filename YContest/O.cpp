/*
 * нужно составить граф
 * каждый из учеников имеет ребро между собой и другим учеником
 * нужно составить граф и проверить его на двудольность
 * можно ли раскрасить в два увета (сфоррмирвоать две группы)
 * по факту проход в глубину с ответками какого цвета данный элемент
 * когда проходишь какой-то из элементов, отмечаем его пройденность
 * две булевы  check и  color
 *
 * если получилось проверить двудольность, то ес, иначе ноу
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int main() {
    int n;
    int m;
    cin >> n;
    cin >> m;
    vector<int> passed(n, -1);
    vector<vector<int>> line(n, vector<int>());


    for (int i = 0; i < m; i++) {
        int x;
        int y;
        cin >> x;
        cin >> y;
        x--;
        y--;
        line[x].push_back(y);
        line[y].push_back(x);
    }

    queue<int> a;
    bool pointer = true;

    for (int i = 0; i < n; i++) {
        if (passed[i] == -1){
            passed[i]=1;
            a.push(i);
            while (!a.empty()){
                int b = a.front();
                a.pop();
                for (int i = 0; i < line[b].size(); i++) {
                    if (passed[line[b][i]] == 1 and passed[b] == 1) {
                        pointer = false;
                    }
                    if (passed[line[b][i]] == 2 and passed[b] == 2) {
                        pointer = false;
                    }
                    if (passed[line[b][i]] == -1) {
                        if (passed[b] == 1) {
                            passed[line[b][i]] = 2;
                        }
                        if (passed[b] == 2) {
                            passed[line[b][i]] = 1;
                        }
                        a.push(line[b][i]);
                    }
                }
            }
        }
    }

    if(pointer == true){
        cout << "YES";
    } else cout << "NO";
}
