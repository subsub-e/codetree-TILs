#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    unordered_set<int> s;
    for(int i = 0; i < a; i++){
        int b; cin >> b;
        s.insert(b);
    }
    int c; cin >> c;
    for(int i = 0; i < c; i++){
        int d; cin >> d;
        if(s.find(d) != s.end()){
            cout << 1 << '\n';
        }
        else{
            cout << 0 << '\n';
        }
    }
    return 0;
}