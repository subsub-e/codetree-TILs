#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    priority_queue<int> pq;
    int a; cin >> a;
    for(int i = 0; i < a; i++){
        string str;
        int a;
        cin >> str;
        if(str == "push"){
            cin >> a;
            pq.push(a);
        }
        else if(str == "size"){
            cout << pq.size() << '\n';
        }
        else if(str == "empty"){
            if(pq.empty()){
                cout << 1 << '\n';
            }
            else{
                cout << 0 << '\n';
            }
        }
        else if(str == "pop"){
            cout << pq.top() << '\n';
            pq.pop();
        }
        else if(str == "top"){
            cout << pq.top() << '\n';
        }
    }
    return 0;
}