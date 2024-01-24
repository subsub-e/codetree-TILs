#include <iostream>
#include <set>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    set<int> s;
    for(int i = 0; i < a; i++){
        s.clear();
        int b; cin >> b;
        for(int j = 0; j < b; j++){
            char c; 
            int d;
            cin >> c >> d;
            if(c == 'I'){
                s.insert(d);
            }
            if(s.size() == 0){
                continue;
            }
            else if(c == 'D'){
                if(d == 1){
                    s.erase(*s.rbegin());
                }
                else{
                    s.erase(*s.begin());
                }
            }
        }
        if(s.size() == 0){
            cout << "EMPTY" << '\n';
        }
        else{
            cout << *s.rbegin() << ' ' << *s.begin() << '\n';
        }
    }
    return 0;
}