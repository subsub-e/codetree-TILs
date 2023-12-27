#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    stack<int> s;
    for(int i = 0; i < a; i++){
        string str; cin >> str;
        int b;
        if(str == "push"){
            cin >> b;
            s.push(b);
        }
        else if(str == "size"){
            cout << s.size() << '\n';
        }
        else if(str == "empty"){
            if(s.size() == 0){
                cout << 1 << '\n';
            }
            else{
                cout << 0 << '\n';
            }
        }
        else if(str == "pop"){
            cout << s.top() << '\n';
            s.pop();
        }
        else if(str == "top"){
            cout << s.top() << '\n';
        }
    }
    return 0;
}