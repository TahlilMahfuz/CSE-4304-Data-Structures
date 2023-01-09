#include <iostream>
#include <queue>

using namespace std;

queue<int>q1;
// Push into the Stack
void push_s(int x) {
   q1.push(x);
}

// Removes the element on top of the stack.
void pop_s() {//pop_back
    queue<int>temp;
    while(q1.size()>1)
    {
        temp.push(q1.front());
        q1.pop();
    }
    q1=temp;
}

// Get the top element.
int top_s() {
   return q1.back();
}

// Return whether the stack is empty.
bool empty_s() {
   return q1.empty();
}

signed main() {
    push_s(10);
    cout << top_s() << endl;
    push_s(20);
    cout << top_s() << endl;
    pop_s();
    cout << top_s() << endl;
    push_s(100);
    cout << top_s() << endl;
    cout << empty_s() << endl;
    pop_s();
    pop_s();
    cout << empty_s() << endl;
}
