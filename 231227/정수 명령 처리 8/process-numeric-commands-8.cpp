#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    list<int> l;                 // 정수를 관리할 list를 선언합니다. => 빈 이중 연결 리스트
    int a; cin >> a;
    for(int i = 0; i < a; i++){
        string str; cin >> str;
        int b;
        if(str == "push_back"){
            cin >> b;
            l.push_back(b);
        }
        else if(str == "push_front"){
            cin >> b;
            l.push_front(b);
        }
        else if(str == "pop_front"){
            cout << l.front() << endl;
            l.pop_front();
        }
        else if(str == "pop_back"){
            cout << l.back() << endl;
            l.pop_back();
        }
        else if(str == "size"){
            cout << l.size() << endl;
        }
        else if(str == "empty"){
            if(l.size() == 0){
                cout << 1 << '\n';
            }
            else{
                cout << 0 << '\n';
            }
        }
        else if(str == "front"){
            cout << l.front() << endl;
        }
        else if(str == "back"){
            cout << l.back() << endl;
        }
    }

    return 0;
}