#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {

	unordered_set<string> planets = {"Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune"};

	for (unsigned i = 0; i < planets.bucket_count(); i++) {
    	cout << "bucket #" << i << " contains:";

    	for (auto it = planets.begin(i); it != planets.end(i); ++it) {
      		cout << " " << *it;
    	}

    	cout << endl;
  	}
	
	return 0;
}