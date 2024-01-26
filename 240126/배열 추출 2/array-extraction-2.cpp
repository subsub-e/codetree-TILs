#include <iostream>
#include <queue>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    priority_queue<int> pq1;
    priority_queue<int> pq2;
    for(int i = 0; i < a; i++){
        int b; cin >> b;
        if(b == 0){
            if(pq1.empty() && pq2.empty()){
                cout << 0 << '\n';
            }
            else{
                if(pq1.top() > pq2.top()){
                    cout << -pq1.top() << '\n';
                    pq1.pop();
                }
                else if(pq1.top() < pq2.top()){
                    cout << pq2.top() << '\n';
                    pq2.pop();
                }
                else if(pq1.empty()){
                    cout << pq2.top() << '\n';
                    pq2.pop();
                }
                else if(pq2.empty()){
                    cout << -pq1.top() << '\n';
                    pq1.pop();
                }
                else{
                    cout << pq2.top() << '\n';
                    pq2.pop();
                }
            }
        }
        else{
            if(b > 0){
                pq1.push(-b);
            }
            else{
                pq2.push(b);
            }
        }
    }
    return 0;
}