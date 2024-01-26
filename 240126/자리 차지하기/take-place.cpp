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
        while(s.find(c) != s.end()){
            c--;

        }
        if(c > b || c < 1){
            continue;
        }
        s.insert(c);
        //index++;
        cnt++;
    }
    cout << cnt;
    return 0;
}