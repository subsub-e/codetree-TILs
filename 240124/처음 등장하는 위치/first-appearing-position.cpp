#include <iostream>
#include <map>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    map<int, int> m;
    for(int i = 1; i <= a; i++){
        int b; cin >> b;
        if(m.find(b) != m.end()){
            continue;
        }
        m[b] = i;
    }
    map<int, int>::iterator it;
    for(it = m.begin(); it != m.end(); it++){
        cout << (it -> first) << ' ' << (it -> second) << '\n';
    }
    return 0;
}