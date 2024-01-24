#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    map<string, double> m;
    for(int i = 0; i < a; i++){
        string str; cin >> str;
        m[str]++;
    }
    map<string, double>::iterator it;
    cout << fixed;
    cout.precision(4);
    for(it = m.begin(); it != m.end(); it++){
        cout << (it -> first) << " " << ((it->second) / a) * 100 << '\n';
    }
    return 0;
}