#include <iostream>
#include <queue>
using namespace std;

enum Priority {
  NORMAL, HIGH
};

template<typename T>
class PriorityQueue {

  private:
  queue<T> normal;
  queue<T> high;

  public:
  void push(T element, Priority priority) {
    if (priority == NORMAL) {
      normal.push(element);
    }

    else if (priority == HIGH) {
      high.push(element);
    }
  }

  void push(T element) {
      normal.push(element);
  }
  

  void pop() {

    if(!high.empty()) {
      high.pop();
    }

    else if (!normal.empty()) {
        normal.pop();
    }

    else {

      cout << "Priority Queue is empty" << endl;
    }
  }

  T front() const {

    if(!high.empty()) {
      return high.front();
    }

    else if (!normal.empty()) {
      return normal.front();
    }

    else {

      cout << "Priority Queue is empty" << endl;
    }
  }

  bool empty() const {

    return normal.empty() && high.empty();
  }
};


int main () {

  PriorityQueue<int> p;

  cout << boolalpha << p.empty();

  p.push(5);
  p.push(15, NORMAL);
  p.push(4, HIGH);

  cout << boolalpha << p.empty();


  while(!p.empty()) {
      cout << p.front() << endl;
      p.pop();
  }

  cout << boolalpha << p.empty();



  
  return 0;
}