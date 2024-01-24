#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    map<string, int> m;
    for(int i = 0; i < a; i++){
        string str; cin >> str;
        m[str]++;
    }
    map<string, int>::iterator it;
    for(it = m.begin(); it != m.end(); it++){
        cout << (it->first) << ' ' << (it -> second) << '\n';
    }
    return 0;
}