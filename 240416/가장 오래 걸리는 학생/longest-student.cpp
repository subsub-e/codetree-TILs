#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
vector<pair<int, int> > v[100001];
int d[100001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
const int INF = 1e9+10;


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    fill(d, d + 1 + n, INF);
    while(m--){
        int x1, x2, cost;
        cin >> x1 >> x2 >> cost;
        v[x1].push_back(make_pair(cost, x2));
        v[x2].push_back(make_pair(cost, x1));
    }

    d[n] = 0;
    pq.push(make_pair(d[n], n));

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

    int maxans = 0;
    for(int i = 1; i <= n; i++){
        maxans = max(maxans, d[i]);
    }

    cout << maxans;
    return 0;
}