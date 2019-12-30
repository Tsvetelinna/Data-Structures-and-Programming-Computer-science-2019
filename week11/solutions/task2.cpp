#include <iostream>
#include <set>
using namespace std;

int main() {

	int n, a, b;
	cout << "n = ";
	cin >> n;

	cout << "a = ";
	cin >> a;

	cout << "b = ";
	cin >> b;

	set<int> numbers;
	int currNum;

	for (int i = 0; i < n; i++) {
		cin >> currNum;
		numbers.insert(currNum);
	}

	for (int i = a; i < b; i++) {

		if (numbers.count(i) != 0) {
			cout << i << " is an element\n";
		}

		else {
			cout << i << " is NOT an element\n";
		}
	}
	cout << endl;
	
	return 0;
}