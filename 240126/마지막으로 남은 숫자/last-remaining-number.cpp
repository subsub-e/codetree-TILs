#include <iostream>
#include <queue>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    priority_queue<int> pq;
    for(int i = 0; i < a; i++){
        int b; cin >> b;
        pq.push(b);
    }
    while(1){
        if(pq.size() < 2){
            break;
        }
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        if(first - second == 0){
            continue;
        }
        pq.push(first - second);
    }
    if(pq.empty()){
        cout << -1;
        return 0;
    }
    cout << pq.top();
    return 0;
}