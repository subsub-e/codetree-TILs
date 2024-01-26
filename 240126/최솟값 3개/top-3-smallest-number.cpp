#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    priority_queue<int> pq;
    for(int i = 0; i < a; i++){
        int b; cin >> b;
        pq.push(-b);
        if(pq.size() < 3){
            cout << -1 << '\n';
        }
        else{
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            int t = pq.top();
            pq.pop();
            cout << abs(f * s * t) << '\n';
            pq.push(f);
            pq.push(s);
            pq.push(t);
        }
    }
    return 0;
}