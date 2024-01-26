#include <iostream>
#include <tuple>
#include <set>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n; cin >> n;
    set<pair<int, int> > s;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        s.insert(make_pair(b, a));
    }
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        string str;
        int c, d;
        cin >> str;
        if(str == "ad"){
            cin >> c >> d;
            s.insert(make_pair(d, c));
        }
        else if(str == "sv"){
            cin >> c >> d;
            s.erase(make_pair(d, c));
        }
        else if(str == "rc"){
            cin >> c;
            if(c == 1){
                cout << s.rbegin()->second << '\n';
            }
            else{
                cout << s.begin()->second << '\n';
            }
        }
    }
    return 0;
}