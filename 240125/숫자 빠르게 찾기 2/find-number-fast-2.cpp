#include <iostream>
#include <set>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    set<int> s;
    int a, b; cin >> a >> b;
    for(int i = 0; i < a; i++){
        int c; cin >> c;
        s.insert(c);
    }
    for(int i = 0; i < b; i++){
        int d; cin >> d;
        if(s.find(d) != s.end()){
            cout << d << '\n';
            continue;
        }
        if(s.upper_bound(d) != s.end()){
            cout << *s.upper_bound(d) << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
    return 0;
}