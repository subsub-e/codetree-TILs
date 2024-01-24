#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int cnt = 0;
    unordered_set<int> s;
    for(int i = 0; i < a; i++){
        int b; cin >> b;
        if(s.find(b) != s.end()){
            continue;
        }
        s.insert(b);
        cnt++;
    }
    cout << cnt;
    return 0;
}