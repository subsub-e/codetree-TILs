#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    vector<pair<int, int> > v;
    int cnt = 1;
    for(int i = 0; i < a; i++){
        int x1, x2; cin >> x1 >> x2;
        v.push_back(make_pair(x2, x1));
    }
    sort(v.begin(), v.end());
    int endtime = v[0].first;
    for(int i = 1; i < a; i++){
        //cout << v[i].second << ' ' << v[i].first << '\n';
        int starttime = v[i].second;
        if(endtime > starttime){
            continue;
        }
        else{
            cnt++;
            endtime = v[i].first;
        }
    }
    cout << cnt;
    return 0;
}