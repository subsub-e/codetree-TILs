#include <iostream>
#include <set>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m; cin >> n >> m;
    set<int> s;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        s.insert(a);
    }
    for(int i = 0; i < m; i++){
        int b; cin >> b;
        set<int>::iterator it = s.upper_bound(b);
        if(it == s.begin()){
            cout << -1 << '\n';
            continue;
        }
        it--;
        cout << *it << '\n';
        s.erase(*it);
    }
    return 0;
}