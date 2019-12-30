#include <iostream>
#include <set>
using namespace std;

int main() {

	int n;
	cin >> n;

	set<int> numbers;
	int currNum;

	for (int i = 0; i < n; i++) {
		cin >> currNum;
		numbers.insert(currNum);
	}

	set<int>::iterator it;

	for (it = numbers.begin(); it != numbers.end(); ++it) {
		cout << *it << " ";
	}

	cout << endl;
	
	return 0;
}