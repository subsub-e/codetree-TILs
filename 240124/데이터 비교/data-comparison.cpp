#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    unordered_set<int> s1;
    unordered_set<int> s2;
    for(int i = 0; i < a; i++){
        int b; cin >> b;
        s1.insert(b);
    }
    int c; cin >> c;
    for(int i = 0; i < c; i++){
        int d; cin >> d;
        if(s1.find(d) != s1.end()){
            cout << 1 << ' ';
        }
        else{
            cout << 0 << ' ';
        }
    }
    // for(int i = 0; i < c; i++){

    // }
    return 0;
}