#include <iostream>
using namespace std;

template <class T>
struct dllnode {
    T data;
    dllnode<T> *next, *prev;
    public:

    dllnode (const T &_data, dllnode *_next = nullptr, dllnode *_prev = nullptr) : data(_data),next(_next),prev(_prev) {
    }
};

template <typename T>
void push_back(dllnode<T>* first, T value) {
    dllnode<T>* curr = first;

    if(first == nullptr) {
        first = new dllnode<T>(value, nullptr, nullptr);
    }

    else {
        dllnode<T>* curr = first;
        while(curr->next != nullptr) {
            curr = curr->next;
        }

        dllnode<T>* newNode = new dllnode<T>(value, nullptr, curr);
        curr->next = newNode;
    }

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

	dllnode<int>* list = new dllnode<int>(2);
	push_back(list, 13);
	push_back(list, 9);
	printDLL(list);

	return 0;
}