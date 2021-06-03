#include <cstdio>
#include <deque>

using namespace std;

deque<int> left;
deque<int> right;

int n;
int middle;
int current;
char operation;

void log() {
	printf("\n%c %d\n", operation, current);
	for (int i = 0; i < left.size(); ++i)
		printf("%d ", left[left.size() - i - 1]);
	printf("| ");
	for (int i = 0; i < right.size(); ++i)
		printf("%d ", right[right.size() - i - 1]);
	printf("\n");

}

// goblin --> back left front --> (middle) back right front --> shaman
// справа >= слева

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf(" %c", &operation);
		switch (operation) {
			case '+':
				scanf(" %d", &current);
				left.push_back(current);
				break;
			case '*':
				scanf(" %d", &current);
				right.push_back(current);
				break;
			case '-':
				current = * right.begin();
				right.pop_front();
				printf("%d\n", current);
				break;
		}
		if (left.size() > right.size()) {
			middle = * left.begin();
			right.push_back(middle);
			left.pop_front();
		}
		//log();
	}
	return 0;
}