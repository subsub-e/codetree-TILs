#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    queue<int> q;
    for(int i = 0; i < a; i++){
        string str; cin >> str;
        int b;
        if(str == "push"){
            cin >> b;
            q.push(b);
        }
        else if(str == "size"){
            cout << q.size() << '\n';
        }
        else if(str == "front"){
            cout << q.front() << '\n';
        }
        else if(str == "pop"){
            cout << q.front() << '\n';
            q.pop();
        }
        else if(str == "empty"){
            if(q.size() == 0){
                cout << 1 << '\n';
            }
            else{
                cout << 0 << '\n';
            }
        }
    }
    return 0;
}