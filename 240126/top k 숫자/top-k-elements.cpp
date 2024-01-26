#include <iostream>
#include <set>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b; cin >> a >> b;
    set<int> s;
    int cnt = 0;
    for(int i = 0; i < a; i++){
        int c; cin >> c;
        // if(s.find(c) != s.end()){
        //     //cout << "pp" << '\n';
        //     continue;
        // }
        s.insert(c);
    }
    set<int>::iterator it;
    while(cnt != b){
        cout << *s.rbegin() << ' ';
        s.erase(*s.rbegin());
        cnt++;
    }
    return 0;
}