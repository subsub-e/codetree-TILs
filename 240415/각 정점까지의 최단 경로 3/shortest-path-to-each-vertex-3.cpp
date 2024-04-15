#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
vector<pair<int, int> > v[101];
int d[101];
priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int, int> > > pq;
const int INF = 1e9+10;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    fill(d, d + n + 1, INF);

    while(m--){
        int x1, x2, cost;
        cin >> x1 >> x2 >> cost;
        v[x1].push_back(make_pair(cost, x2));
    }

    d[1] = 0;
    pq.push(make_pair(d[1], 1));

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
        }
    }

    for(int i = 2; i <= n; i++){
        if(d[i] == INF){
            cout << -1 << '\n';
        }
        else{
            cout << d[i] << '\n';
        }
    }
    return 0;
}