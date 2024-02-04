#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n; cin >> n;
    vector<pair<int, int> > v;
    for(int i = 0; i < n; i++){
        int s, e; cin >> s >> e;
        v.push_back(make_pair(e, s));
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    // for(int i = 0; i < n; i++){
    //     cout << v[i].first << ' ' << v[i].second << '\n';
    // }
    int index = 0;
    for(int i = 1; i < n; i++){
        if(v[i].second >= v[index].first){
            index = i;
        }
        else{
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}