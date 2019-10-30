#include <iostream>
#include <queue>
using namespace std;

template <typename T>
T minElementInQueue(queue<T> q) {

	T size = q.size();
	T min = q.front();

	for (int i = 0; i < size; i++) {
		T front = q.front();

		if (min > front) {
			min = front;
		}

		q.pop();
		q.push(front);
	}

	return min;
}

template <typename T>
T minElementInQueue2(queue<T> q) {

	T size = q.size();
	T min = q.front();

	while(!q.empty()) {
		T front = q.front();

		if (min > front) {
			min = front;
		}

		q.pop();
	}

	return min;
}

int main () {

	queue<int> q;
    q.push(7);
    q.push(0);
    q.push(5);
    q.push(20);
    q.push(-1);
    q.push(15);

    cout << minElementInQueue(q);
	
	return 0;
}