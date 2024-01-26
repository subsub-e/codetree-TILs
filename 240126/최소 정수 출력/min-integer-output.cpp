#include <iostream>
#include <queue>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    priority_queue<int> pq;
    for(int i = 0; i < a; i++){
        int b; cin >> b;
        b = -b;
        if(b == 0){
            if(pq.empty()){
                cout << 0 << '\n';
            }
            else{
                cout << -pq.top() << '\n';
                pq.pop();
            }
        }
        else{
            pq.push(b);
        }
    }
    return 0;
}