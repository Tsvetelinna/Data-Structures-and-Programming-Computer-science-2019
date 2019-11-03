#include<list>
using namespace std;

void addElement(int position, int element, list<int>& myList) {

    if(myList.size() < position) {
        cout << "List`s size is smaller than position:" << position << endl;
    }

    list<int>::iterator it = myList.begin(); 

    while(position) {
        ++it;
        position--;
    }

    myList.insert(it, element);
}

int main() {

    int position;
    int element;

    cin >> position;
    cin >> element;

    list<int> myList;
    myList.push_front(5);
    myList.push_front(15);
    myList.push_front(8);
    myList.push_front(22);    
    myList.push_front(13);


    addElement(position, element, myList);

	list<int>::iterator it;

    for(it = myList.begin(); it != myList.end(); ++it){
    	cout << ' ' << *it;
    }
    cout<<endl;


	return 0;
}