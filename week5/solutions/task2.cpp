#include <iostream>
using namespace std;

template <class T>
struct sllnode {
    T data;
    sllnode<T> *next;
    public:

    sllnode (const T &_data, sllnode *_next = nullptr) : data(_data),next(_next) {
    }
};

sllnode<int>* createSLList(int n){

	int count = 0;

	sllnode<int>* first = new sllnode<int>(count, nullptr);
	sllnode<int>* curr = first;

	while(count < n) {
		curr->next = new sllnode<int>(++count, nullptr);
		curr = curr->next;
	}

	return first;
}

template <class T>
T middle(sllnode<T>* first) {

	sllnode<T>* crr = first; 
	sllnode<T>* mid = first;

	if(first == nullptr) {
		return -1;
	}

	while(crr->next != nullptr){
		crr = crr->next;

		if(crr->next != nullptr){
			crr = crr->next;
		}

		mid = mid->next;
	}

	return mid->data;
}

template <typename T>
void printSLL(sllnode<T>* first) {

	sllnode<T>* crr = first;

	while(crr){
		cout << crr->data << " ";
		crr = crr->next;
	}
	
	cout << endl;
}

int main () {

	int n;

	cin >> n;

	sllnode<int>* list = createSLList(n);
	printSLL(list);

	int mid = middle(list);
	cout << "Middle of list:" << mid << endl;

	return 0;
}