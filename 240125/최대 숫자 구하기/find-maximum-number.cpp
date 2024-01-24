#include <iostream>
#include <set>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m; cin >> n >> m;
    set<int> s;
    for(int i = 1; i <= m; i++){
        s.insert(i);
    }
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        s.erase(a);
        cout << *s.rbegin() << '\n';
    }
    return 0;
}