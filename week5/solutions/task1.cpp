#include <iostream>
using namespace std;

template <class T>
struct sllnode {
    T data;
    sllnode<T>* next;

    public:
    sllnode (const T &_data, sllnode* _next = nullptr) : data(_data),next(_next) {
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

	return 0;
}