#include <iostream>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

int a;
bool visited[1000001];
int step[1000001];
int ans = INT_MAX;
queue<int> q;

void Push(int x, int cnt){
    //cout << x << '\n';
    if(visited[x] == 1){
        if(step[x] < cnt){
            return;
        }
        else{
            if(x == 1){
                ans = min(ans, step[x]);
                return;
            }
            step[x] = cnt;
            q.push(x);
        }
    }
    else{
        if(x == 1){
            cout << cnt;
            exit(0);
        }
        visited[x] = 1;
        step[x] = cnt;
        q.push(x);
    }
}

void bps(){
    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x % 3 == 0){
            Push(x / 3, step[x] + 1);
        }
        if(x % 2 == 0){
            Push(x / 2, step[x] + 1);
        }
        Push(x - 1, step[x] + 1);
        Push(x + 1, step[x] + 1); 
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a;
    Push(a, 0);
    bps();
    cout << ans;
    return 0;
}