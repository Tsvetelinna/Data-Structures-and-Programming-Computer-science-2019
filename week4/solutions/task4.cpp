#include<iostream>
#include<list>
using namespace std;

bool singleDigit (const int& value) { 
    return (value<10); 
}

void removeSingleDigitElement(list<int>& myList) {
    myList.remove_if(singleDigit);
}

int main() {
    
    list<int> myList;

    for(int i = 5; i < 15; i++) {
        myList.push_back(i);
    }

    removeSingleDigitElement(myList);

    list<int>::iterator it;

    for(it = myList.begin(); it != myList.end(); ++it){
        cout << ' ' << *it;
    }
    cout<<endl;

	return 0;
}