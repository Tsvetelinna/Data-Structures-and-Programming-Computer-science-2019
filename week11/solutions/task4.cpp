#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {

	map<int, string> cities;
	map<int, string>::iterator it;

	int n;
	cout << "n = ";
	cin >> n;
	string city;

	for (int i = 0; i < n; i++) {
		cin >> city;
		cities[city.size()] = city;
	}

	cout << "Cities:" << endl;

	for (it = cities.begin(); it != cities.end(); ++it) {
		cout << it->first << " => " << it->second << '\n';
	}

	it = cities.end();
	it--;
	cities.erase(it);

	cout << "Cities after erase:" << endl;

	for (it = cities.begin(); it != cities.end(); ++it) {
		cout << it->first << " => " << it->second << '\n';
	}

	return 0;
}