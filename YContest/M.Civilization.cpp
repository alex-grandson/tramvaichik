#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct Node {
    int x;
    int y;
    int dist; // расстояние от стартовой точки
    char type;
    bool visited;
    Node * prev;
};

bool operator== (const Node &left, const Node &right) {
    return (right.x == left.x && right.y == left.y);
}

int n;
int m;
Node start;
Node finish;

int main() {
    scanf("%d %d %d %d %d %d",
          &n, &m, &start.x, &start.y, &finish.x, &finish.y);
    start.x--;
    start.y--;
    finish.x--;
    finish.y--;

    vector< vector<Node> > a(n, vector<Node>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf(" %c", &a[i][j].type);
            a[i][j].x = i;
            a[i][j].y = j;
            a[i][j].visited = false;
            if (a[i][j] == start) {
                a[i][j].dist = 0;
            } else {
                a[i][j].dist = INT_MAX;
            }
        }
    }


    // дейкстра для поиска путей до всех точек
    vector<Node*> front;
    front.reserve(n * m);
    front.push_back( &a[start.x][start.y] );

    for (int i = 0; i < n * m; ++i) {
        Node *temp = front[0];

        /*
         * есть temp, у нее набор соседей
         * всех соседей нужно на фронт, но с условиеем
         * 1. если сосед чекнут - не добавляет
         * 2*. если во фронте - тоже не добавялть (есть нюансы)
         * когда происходит вставка элемента, нужно знать расстояние до него
         * temp.dist + тип ноды, которую хотим вставлять
         *
         * реализация вставки через хипарь
         * у хип есть
         * make_heap
         * pop_heap
         * push_heap
         * структура, итератор бегин енд и компаратор
         * компарато в свою очередь завязан на дистанцию
         * (функция. проверяющая дистанции)
         * return a.dist > b.dist
         *
         */
    }
    /*
     * Node * iter = & end;
     * while(iter)
     * iter.prev где был
     * push_front deque - ответ путя
     */

    // восстановление ответа
    vector<char> ans;




    return 0;
}

/*
 for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%c", a[i][j].type);
        }
        printf("\n");
    }
 */