#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
vector<pair<int, int> > v[1001];
int d[1001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
const int INF = 1e9 + 10;
int st, en;


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

    for(int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end());
    }

    cin >> st >> en;
    d[en] = 0;
    pq.push(make_pair(d[en], en));

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

    cout << d[st] << '\n';

    cout << st << ' ';

    while(st != en){
        vector<pair<int, int> > &ans = v[st];
        for(int i = 0; i < (int)ans.size(); i++){
            if(d[st] == d[ans[i].second] + ans[i].first){
                st = ans[i].second;
                break;
            }
        }
        cout << st << ' ';
    }

    
    return 0;
}