#include <iostream>
#include <queue>
using namespace std;

template <typename T>
queue<T> merge(queue<T> first, queue<T> second) {
    queue<T> result;

    while (!first.empty() && !second.empty()) {

        if (first.front() <= second.front()) {
            result.push(first.front());
            first.pop();
        }

        else {
            result.push(second.front());
            second.pop();
        }
    }

    while(!first.empty()) {
        result.push(first.front());
        first.pop();
    }

    while (!second.empty()) {
        result.push(second.front());
        second.pop();
    }

    return result;
}

int main () {

    queue<int> f;
    f.push(1);
    f.push(5);
    f.push(10);

    queue<int> s;
    s.push(7);
    s.push(9);
    s.push(15);

    queue<int> res = merge(f, s);

    while (!res.empty()) {
        cout << res.front();

        res.pop();

    }
    
    return 0;
}
