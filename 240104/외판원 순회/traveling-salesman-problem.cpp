#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int a;
int arr[10][10];
int ans = INT_MAX;
bool visited[10001];
vector<int> v;

int calc(){
    int cost = 0;
    v.push_back(0);
    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i] << ' ';
    // }
    
    for(int i = 1; i < v.size(); i++){
        if(arr[v[i - 1]][v[i]] == 0){
            v.pop_back();
            return INT_MAX;
        }
        cost += arr[v[i - 1]][v[i]];
    }
    v.pop_back();
    //cout << cost << '\n';
    return cost;
}

void simulate(int cnt){
    if(cnt == a){
        ans = min(ans, calc());
        return;
    }

    for(int i = 0; i < a; i++){
        if(visited[i] == true){
            continue;
        }
        if(v.size() > 0 && v[0] != 0){
            continue;
        }

        visited[i] = true;
        v.push_back(i);
        simulate(cnt + 1);
        visited[i] = false;
        v.pop_back();
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cin >> arr[i][j];
        }
    }
    simulate(0);
    cout << ans;
    return 0;
}