#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n; cin >> n;
    vector<pair<int, int> > v;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        sum += x;
        v.push_back(make_pair(y, x));
    }
    sum /= 2;
    sort(v.begin(), v.end());
    // for(int i = 0; i < n; i++){
    //     cout << v[i].first << ' ' << v[i].second << '\n';
    // }
    // cout << sum;
    int index = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        index += v[i].second;
        if(index == sum){
            ans = v[i].first + v[i + 1].first;
            break;
        }
        else if(index > sum){
            ans = v[i].first * 2;
            break;
        }
    }
    cout << ans;
    return 0;
}