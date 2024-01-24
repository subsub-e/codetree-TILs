#include <iostream>
#include <set>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b; cin >> a >> b;
    set<pair<int, int> > s;
    for(int i = 0; i < a; i++){
        int c, d; cin >> c >> d;
        s.insert(make_pair(c, d));
    }
    for(int i = 0; i < b; i++){
        int c, d; cin >> c >> d;
        auto it = s.lower_bound(make_pair(c, d));
        if(it == s.end()){
            cout << -1 << ' ' << -1 << '\n';
            continue;
        }
        pair<int, int> p = *s.lower_bound(make_pair(c, d));
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}