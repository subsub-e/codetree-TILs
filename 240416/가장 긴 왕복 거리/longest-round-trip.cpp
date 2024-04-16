#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, m, st;
vector<pair<int, int> > v[1001];
vector<pair<int, int> > v1[1001];
int d[1001];
int d1[1001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
const int INF = 1e9+10;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> st;
    fill(d, d + n + 1, INF);
    fill(d1, d1 + n + 1, INF);

    while(m--){
        int x1, x2, cost;
        cin >> x1 >> x2 >> cost;
        v[x1].push_back(make_pair(cost, x2));
        v1[x2].push_back(make_pair(cost, x1));
    }

    d[st] = 0;
    pq.push(make_pair(d[st], st));
    while(!pq.empty()){
        int cur_dist = pq.top().first;
        int cur_x = pq.top().second;
        pq.pop();

        if(d[cur_x] != cur_dist){
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

    d1[st] = 0;
    pq.push(make_pair(d1[st], st));
    while(!pq.empty()){
        int cur_dist = pq.top().first;
        int cur_x = pq.top().second;
        pq.pop();

        if(d1[cur_x] != cur_dist){
            continue;
        }

        for(auto next : v1[cur_x]){
            if(d1[next.second] <= next.first + d1[cur_x]){
                continue;
            }
            d1[next.second] = next.first + d1[cur_x];
            pq.push(make_pair(d1[next.second], next.second));
        }
    }

    int maxans = 0;
    for(int i = 1; i <= n; i++){
        if(d[i] >= INF || d1[i] >= INF){
            continue;
        }
        maxans = max(maxans, d[i] + d1[i]);
    }
    cout << maxans;
    return 0;
}