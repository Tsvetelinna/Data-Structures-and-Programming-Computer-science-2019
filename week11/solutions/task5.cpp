#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void deleteCountry(unordered_map<string, string>& countries, string countryToDelete) {
	countries.erase(countryToDelete);
}

int main() {

	unordered_map<string, string> countries;
	unordered_map<string, string>::iterator it;

	int n;
	cout << "n = ";
	cin >> n;
	string country, capitals;

	for (int i = 0; i < n; i++) {
		cin >> country;
		cin >> capitals;
		countries[country] = capitals;
	}

	for (auto& x: countries) {
		cout << x.first << ": " << x.second << endl;
	}

	string countryToDelete;
	cout << "Delete country:";
	cin >> countryToDelete;

	deleteCountry(countries, countryToDelete);

	for (auto& x: countries) {
		cout << x.first << ": " << x.second << endl;
	}

	return 0;
}