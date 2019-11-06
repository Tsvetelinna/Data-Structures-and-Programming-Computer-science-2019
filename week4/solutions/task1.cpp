#include<iostream>
#include<list>
using namespace std;

int main() {

    int n;
    int k;

    cin >> n;
    cin >> k;

	// list<int> myList(n, k);
    list<int> myList;
    myList.assign(n, k);
    
	list<int>::iterator it;

    for(it = myList.begin(); it != myList.end(); ++it){
    	cout << ' ' << *it;
    }
    cout<<endl;


	return 0;
}