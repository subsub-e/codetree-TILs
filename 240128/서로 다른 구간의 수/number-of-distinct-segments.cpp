#include <iostream>
#include <tuple>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    vector<tuple<int, int, int> > v;
    for(int i = 0; i < a; i++){
        int x1, x2; cin >> x1 >> x2;
        v.push_back(make_tuple(x1, +1, i));
        v.push_back(make_tuple(x2, -1, i));
    }
    sort(v.begin(), v.end());

    int cnt = 0;
    unordered_set<int> s;

    for(int i = 0; i < a * 2; i++){
        int x, y, z;
        tie(x, y, z) = v[i];

        if(y == +1){
            if(s.empty()){
                cnt++;
            }
            s.insert(z);
        }
        else{
            s.erase(z);
        }
    }
    cout << cnt;
    return 0;
}