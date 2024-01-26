#include <iostream>
#include <vector>
#include <set>
#include <tuple>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m; cin >> n >> m;
    //vector<pair<int, int> > v;
    set<pair<int, int> > s;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        s.insert(make_pair(a, b));
    }
    for(int i = 0; i < m; i++){
        int c; cin >> c;
        if(s.upper_bound(make_pair(c, -1)) == s.end()){
            cout << "-1 -1" << '\n';
        }
        else{
            pair<int, int> tmp = *s.upper_bound(make_pair(c, -1));
            int x, y;
            tie(x, y) = tmp;
            cout << x << ' ' << y << '\n';
            s.erase(tmp);
        }
    }
    return 0;
}