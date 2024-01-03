#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<pair <int, int>> v;
vector<pair <int, int>> que;

int n, m;
//int arr[20][2];
int ans = INT_MAX;


int calc(){
    int maxans = 0;
    // for(int i = 0; i < m; i++){
    //     cout << v[i].first << ' ' << v[i].second << '\n';
    // }
    // cout << '\n';
    for(int i = 0; i < m; i++){
        for(int j = i + 1; j < m; j++){
            int calc_num = (v[j].first - v[i].first) * (v[j].first - v[i].first) + (v[j].second - v[i].second) * (v[j].second - v[i].second);
            maxans = max(maxans, calc_num);
        }
    }
    //cout << maxans << '\n';
    return maxans;
}

void simulate(int index, int count){
    if(count == m){
        ans = min(ans, calc());
        return;
    }

    for(int i = index; i < n; i++){
        int x, y;
        tie(x, y) = que[i];
        v.push_back({x, y});
        //cout << index << ' ' << count << '\n';
        simulate(i + 1, count + 1);
        v.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        que.push_back(make_pair(x, y));
    }
    simulate(0, 0);
    cout << ans;
    return 0;
}