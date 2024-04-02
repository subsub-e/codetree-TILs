#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m;
int uf[10001];
char c[10001];
tuple<int, int, int> arr[100001];

int find(int x){
    if(uf[x] == x){
        return x;
    }
    return uf[x] = find(uf[x]);
}

void Union(int x, int y){
    int X = find(x);
    int Y = find(y);
    uf[X] = Y;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }

    for(int i = 1; i <= n; i++){
        uf[i] = i;
    }

    for(int i = 1; i <= m; i++){
        int x1, x2, cost;
        cin >> x1 >> x2 >> cost;
        arr[i] = make_tuple(cost, x1, x2);
    }

    sort(arr + 1, arr + 1 + m);

    int ans = 0;
    for(int i = 1; i <= m; i++){
        int x, y, cost;
        tie(cost, x, y) = arr[i];

        if(c[x] == c[y]){
            continue;
        }

        if(find(x) != find(y)){
            ans += cost;
            Union(x, y);
        }
    }

    int flag = 0;
    for(int i = 2; i <= n; i++){
        int x = find(1);
        int y = find(i);
        if(x != y){
            flag = 1;
        }
    }

    if(flag == 1){
        cout << -1;
    }
    else{
        cout << ans;
    }
    
    return 0;
}