#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

int n, m;
vector<pair<int, int> > v[100001];
int d[100001];
int abc_d[100001];
int x1, x2, x3;
const int INF = 1e9+10;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

void func(int x){
    fill(d, d + n + 1, INF);
    d[x] = 0;
    pq.push(make_pair(d[x], x));
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

    for(int i = 1; i <= n; i++){
        abc_d[i] = min(abc_d[i], d[i]);
    }

}
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> x1 >> x2 >> x3;
    fill(abc_d, abc_d + 1 + n, INF);

    while(m--){
        int f, s, cost;
        cin >> f >> s >> cost;
        v[f].push_back(make_pair(cost, s));
        v[s].push_back(make_pair(cost, f));
    }

    func(x1);
    func(x2);
    func(x3);

    

    int maxans = -1;

    for(int i = 1; i <= n; i++){
        maxans = max(maxans, abc_d[i]);
    }
    cout << maxans;
    return 0;
}