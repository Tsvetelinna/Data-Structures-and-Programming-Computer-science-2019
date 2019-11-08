#include <iostream>
using namespace std;

template <class T>
struct dllnode {
    T data;
    dllnode<T>* next;
    dllnode<T>* prev;

    public:
    dllnode (const T &_data, dllnode* _next = nullptr, dllnode* _prev = nullptr) : data(_data),next(_next),prev(_prev) {
    }
};

dllnode<int>* createDLList(int n) {

	dllnode<int>* first = new dllnode<int>(n, nullptr, nullptr);
	dllnode<int>* curr = first;

	while(n > 0) {
		curr->next = new dllnode<int>(--n, nullptr, curr);
		curr->prev = curr;
		curr = curr->next;
	}

	return first;
}

template <typename T>
void printDLL(dllnode<T>* first) {

	dllnode<T>* crr = first;

	while(crr) {
		cout << crr->data << " ";
		crr = crr->next;
	}

	cout << endl;
}

int main () {

	int n;

	cin >> n;

	dllnode<int>* list = createDLList(n);
	printDLL(list);

	return 0;
}