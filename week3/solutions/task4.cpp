#include <iostream>
#include <queue>
using namespace std;

template <typename T>
bool isExistingInQuque(queue<T> q, T element) {

	T size = q.size();
	T min = q.front();

	for (int i = 0; i < size; i++) {
		T front = q.front();

		if (element == front) {
			return true;
		}

		q.pop();
		q.push(front);
	}

	return false;
}

int main () {

	queue<int> q;
    q.push(7);
    q.push(0);
    q.push(5);
    q.push(20);
    q.push(-1);
    q.push(15);

    cout << boolalpha << isExistingInQuque(q, 155);
	
	return 0;
}