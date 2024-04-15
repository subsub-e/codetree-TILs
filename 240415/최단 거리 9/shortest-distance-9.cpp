#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

int n, m;
vector<pair<int, int> > v[1001];
int d[1001];
const int INF = 1e9 + 10;
int path[1001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int st, en;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    fill(d, d + n + 1, INF);
    while(m--){
        int x1, x2, cost;
        cin >> x1 >>x2 >> cost;
        v[x1].push_back(make_pair(cost, x2));
        v[x2].push_back(make_pair(cost, x1));
    }
    cin >> st >> en;

    d[st] = 0;
    pq.push(make_pair(d[st], st));

    while(!pq.empty()){
        int cur_x = pq.top().first;
        int cur_y = pq.top().second;
        pq.pop();

        if(d[cur_y] != cur_x){
            continue;
        }

        for(auto next : v[cur_y]){
            if(d[next.second] <= next.first + d[cur_y]){
                continue;
            }
            d[next.second] = next.first + d[cur_y];
            pq.push(make_pair(d[next.second], next.second));
            path[next.second] = cur_y;
        }
    }

    cout << d[en] << '\n';

    vector<int> ans;
    ans.push_back(en);
    while(en != st){
        en = path[en];
        ans.push_back(en);
    }

    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }


    return 0;
}