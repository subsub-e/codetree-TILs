#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    deque<int> d;
    for(int i = 0; i < a; i++){
        string str; cin >> str;
        int b;
        if(str == "push_front"){
            cin >> b;
            d.push_front(b);
        }
        else if(str == "push_back"){
            cin >> b;
            d.push_back(b);
        }
        else if(str == "pop_front"){
            cout << d.front() << '\n';
            d.pop_front();
        }
        else if(str == "pop_back"){
            cout << d.back() << '\n';
            d.pop_back();
        }
        else if(str == "size"){
            cout << d.size() << '\n';
        }
        else if(str == "empty"){
            if(d.size() == 0){
                cout << 1 << '\n';
            }
            else{
                cout << 0 << '\n';
            }
        }
        else if(str == "front"){
            cout << d.front() << '\n';
        }
        else if(str == "back"){
            cout << d.back() << '\n';
        }
    }
    return 0;
}