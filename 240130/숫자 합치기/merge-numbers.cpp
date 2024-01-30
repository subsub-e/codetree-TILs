#include <iostream>
#include <queue>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int sum = 0;
    int a; cin >> a;
    priority_queue<int> q;
    for(int i = 0; i < a; i++){
        int x; cin >> x;
        q.push(-x);
    }
    while(q.size() > 1){
        int b1 = q.top();
        q.pop();
        int b2 = q.top();
        q.pop();
        b1 = -b1;
        b2 = -b2;
        int p = b1 + b2;
        q.push(-p);
        // for(int i = 0; i < q.size(); i++){
        //     cout << q.top()
        // }
        sum += p;
    }
    cout << sum;
    return 0;
}