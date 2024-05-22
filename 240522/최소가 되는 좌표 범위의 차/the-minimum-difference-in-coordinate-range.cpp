#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m; cin >> n >> m;
    vector<pair<int, int> > v;
    for(int i = 0; i < n; i++){
        int x1, x2; cin >> x1 >> x2;
        v.push_back(make_pair(x1, x2));
    }
    sort(v.begin(), v.end());

    int minans = INT_MAX;
    int st = 0;
    int en = 1;
    while(st < n - 1){
        while(en < n && abs(v[en].second - v[st].second) >= m){
            int temp = (v[en].first - v[st].first);
            //cout << v[en].second << ' ' << v[st].second << '\n';
            minans = min(minans, abs(temp));
            en++;
        }
        if(en == n){
            while(st < n && abs(v[en - 1].second - v[st].second) >= m){
                int temp = (v[en - 1].first - v[st].first);
                //cout << v[en].second << ' ' << v[st].second << '\n';
                minans = min(minans, abs(temp));
                st++;
            }
            break;
        }
        // int temp = (v[en].second - v[st].second);
        // minans = min(minans, abs(temp));
        if(st + 1 == en){
            en++;
        }
        else{
            st++;
        }
        //cout << st << ' ' << en << ' ' << (v[en].second - v[st].second) << '\n';
    }
    if(minans == INT_MAX){
        cout << -1;
    }
    else{
        cout << minans;
    }

    return 0;
}