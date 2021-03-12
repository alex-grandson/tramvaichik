#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Animal {
    char letter;
    int index;
};

int abs (int a) {
    if (a < 0) return -a;
    return a;
}
int isPair (int a, int b) {
    if ('a' <= a && a <= 'z' && 'A' <= b && b <= 'Z' ||
        'a' <= b && b <= 'z' && 'A' <= a && a <= 'Z')
        if (abs(a - b) == 'a' - 'A')
            return 1;
    return 0;
}
int isBigLetter (int a) {
    if ('A' <= a && a <= 'Z') return 1;
    return 0;
}

int main(){
    string s;
    cin >> s;
    vector<Animal> zoopark;
    vector<int> ans;
    int n = 0, n2 = 0;
    for (char i : s) {
        Animal animal;
        animal.letter = i;
        if (isBigLetter(i)) {
            n += 1;
            animal.index = n;
        } else {
            n2 += 1;
            animal.index = n2;
        }
        zoopark.push_back(animal);
    }
    while (!zoopark.empty()) {


            int sizeBefore = zoopark.size();
            for (int i = 1; i < zoopark.size(); i++) {
                if (isPair(zoopark[i - 1].letter, zoopark[i].letter)) {
                    if (isBigLetter(zoopark[i - 1].letter)) ans.push_back(zoopark[i].index);
                    else ans.push_back(zoopark[i - 1].index);
                	zoopark.erase(zoopark.begin() + i - 1);
                    zoopark.erase(zoopark.begin() + i - 1);
                }
            }
            if (sizeBefore == zoopark.size()) {
                cout << "Impossible";
                return 0;
            }

    }
    cout << "Possible" << endl;
    reverse(ans.begin(), ans.end());
    for (int i: ans) cout << i << " ";

    return 0;
}