#include<iostream>
#include<list>
using namespace std;

bool find(int n, list<int>& myList) {

    list<int>::iterator it;
    for(it = myList.begin(); it != myList.end(); ++it){
        if(*it == n) {
            myList.erase(it);
            return true;
        }
    }

    return false;
}

int main() {

    int n;

    cin >> n;

    list<int> myList;
    myList.push_front(5);
    myList.push_front(15);
    myList.push_front(8);
    myList.push_front(22);    
    myList.push_front(13);


    cout << boolalpha << find(n, myList) << endl;

	list<int>::iterator it;

    for(it = myList.begin(); it != myList.end(); ++it){
    	cout << ' ' << *it;
    }
    cout<<endl;


	return 0;
}