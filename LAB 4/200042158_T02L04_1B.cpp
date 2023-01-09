#include <iostream>
#include <queue>

using namespace std;

queue<int>q;

int ping(int t) {
    // YOUR CODE HERE
    q.push(t);
    while(q.front()<t-3000)
    {
        q.pop();
    }
    return q.size();
}

signed main() {
    cout << ping(1) << "\n";
    cout << ping(2) << "\n";
    cout << ping(3) << "\n";
    cout << ping(4) << "\n";
    cout << ping(3001) << "\n";
    cout << ping(3002) << "\n";
    cout << ping(3003) << "\n";
    cout << ping(6003) << "\n";
    cout << ping(10003) << "\n";

    return 0;
}
