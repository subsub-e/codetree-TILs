#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
vector<pair<int, int> > v[1001];
int d[1001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int st, en;
const int INF = 1e9 +10;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    fill(d, d + n + 1, INF);
    while(m--){
        int x1, x2, cost;
        cin >> x1 >> x2 >> cost;
        v[x1].push_back(make_pair(cost, x2));
        v[x2].push_back(make_pair(cost, x1));
    }

    cin >> st >> en;

    d[st] = 0;
    pq.push(make_pair(d[st], st));
    while(!pq.empty()){
        int cur_dist = pq.top().first;
        int cur_x = pq.top().second;
        pq.pop();

        if(cur_dist != d[cur_x]){
            continue;
        }

        for(auto next : v[cur_x]){
            if(d[next.second] <= next.first + d[cur_x]){
                continue;
            }
            d[next.second] = next.first + d[cur_x];
            pq.push(make_pair(d[next.second], next.second));
        }
    }

    cout << d[en];
    return 0;
}