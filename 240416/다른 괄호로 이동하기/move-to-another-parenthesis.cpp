#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, m, cost1, cost2;
char que[31][31];
int arr[31][31];
vector<pair<int, int> > v[901];
int d[901];
const int INF = 1e9 + 10;

void func(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            arr[i][j] = ++m;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j =1; j <= n; j++){
            int dx[4] = {-1, 1, 0, 0};
            int dy[4] = {0, 0, -1, 1};

            for(int k = 0; k < 4; k++){
                int nx = i + dx[i];
                int ny = j + dy[i];
                if(0 < nx && nx <= n && 0 < ny && ny <= n){
                    int node1 = arr[i][j];
                    int node2 = arr[nx][ny];
                    int cost;
                    if(que[i][j] == que[nx][ny]){
                        cost = cost1;
                    }
                    else{
                        cost = cost2;
                    }
                    v[node1].push_back(make_pair(cost, node2));
                }
            }
        }
    }
}

void dijkstra(int x){
    fill(d, d + n*n + 1, INF);

    d[x] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(d[x], x));

    while(!pq.empty()){
        int cur_dist = pq.top().first;
        int cur_x = pq.top().second;
        pq.pop();

        if(d[cur_x] != cur_dist){
            continue;
        }

        for(auto next : v[cur_x]){
            if(d[next.second] <= d[cur_x] + next.first){
                continue;
            }

            d[next.second] = d[cur_x] + next.first;
            pq.push(make_pair(d[next.second], next.second));
        }
    }
}

int main(){
    cin >> n >> cost1 >> cost2;
    for(int i= 1; i <= n; i++){
        for(int j =1; j <= n;j++){
            cin >> que[i][j];
        }
    }
    

    func();
    int maxans = 0;

    for(int i = 1; i <= m; i++){
        dijkstra(i);

        for(int j = 1; j <= m; j++){
            if(d[j] >= INF){
                continue;
            }
            maxans = max(maxans, d[j]);
        }
    }

    cout << maxans;

    return 0;
}