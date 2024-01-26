#include <iostream>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m; cin >> n >> m;
    set<int> s;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        s.insert(a);
    }
    int minans = INT_MAX;
    for(set<int>::iterator it = s.begin(); it != s.end()--; it++){
        set<int>::iterator next = s.lower_bound(*it - m);
        if(next != s.begin()){
            next--;
            minans = min(minans, *it - *next);
        }
    }
    if(minans == INT_MAX){
        cout << -1;
        return 0;
    }
    cout << minans;
    return 0;
}