#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

int n, m;
vector<pair<int, int> > v[100001];
int d1[100001];
int d2[100001];
int d3[100001];
int x1, x2, x3;
const int INF = 1e9+10;


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> x1 >> x2 >> x3;
    fill(d1, d1 + 1 + n, INF);
    fill(d2, d2 + 1 + n, INF);
    fill(d3, d3 + 1 + n, INF);

    while(m--){
        int f, s, cost;
        cin >> f >> s >> cost;
        v[f].push_back(make_pair(cost, s));
        v[s].push_back(make_pair(cost, f));
    }

    d1[x1] = 0;
    d2[x2] = 0;
    d3[x3] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(d1[x1], x1));
    while(!pq.empty()){
        int cur_dist = pq.top().first;
        int cur_x = pq.top().second;
        pq.pop();

        if(d1[cur_x] != cur_dist){
            continue;
        }

        for(auto next : v[cur_x]){
            if(d1[next.second] <= next.first + d1[cur_x]){
                continue;
            }
            d1[next.second] = next.first + d1[cur_x];
            pq.push(make_pair(d1[next.second], next.second));
        }
    }

    pq.push(make_pair(d2[x2], x2));
    while(!pq.empty()){
        int cur_dist = pq.top().first;
        int cur_x = pq.top().second;
        pq.pop();

        if(d2[cur_x] != cur_dist){
            continue;
        }

        for(auto next : v[cur_x]){
            if(d2[next.second] <= next.first + d2[cur_x]){
                continue;
            }
            d2[next.second] = next.first + d2[cur_x];
            pq.push(make_pair(d2[next.second], next.second));
        }
    }

    pq.push(make_pair(d3[x3], x3));
    while(!pq.empty()){
        int cur_dist = pq.top().first;
        int cur_x = pq.top().second;
        pq.pop();

        if(d3[cur_x] != cur_dist){
            continue;
        }

        for(auto next : v[cur_x]){
            if(d3[next.second] <= next.first + d3[cur_x]){
                continue;
            }
            d3[next.second] = next.first + d3[cur_x];
            pq.push(make_pair(d3[next.second], next.second));
        }
    }

    int maxans = -1;

    for(int i = 1; i <= n; i++){
        if(i == x1 || i == x2 || i == x3){
            continue;
        }
        int temp = min(d1[i], min(d2[i], d3[i]));
        maxans = max(maxans, temp);
    }
    cout << maxans;
    return 0;
}