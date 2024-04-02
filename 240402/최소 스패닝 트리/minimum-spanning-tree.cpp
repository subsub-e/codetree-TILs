#include <iostream>
#include <tuple>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
tuple<int, int, int> arr[100001];
int uf[10001];

int find(int x){
    if(uf[x] == x){
        return x;
    }
    return uf[x] = find(uf[x]);
}

void Union(int x, int y){
    int pos_x = find(x);
    int pos_y = find(y);
    uf[pos_x] = pos_y;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    //memset(uf, -1, sizeof(uf));
    for(int i = 0; i < m; i++){
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;
        arr[i] = make_tuple(x3, x1, x2);
    }
    sort(arr + 1, arr + m + 1);

    for(int i = 1; i <= m; i++){
        uf[i] = i;
    }

    int ans = 0;

    for(int i = 0; i < m; i++){
        int a, b, cost;
        tie(cost, a, b) = arr[i];
        if(find(a) != find(b)){
            ans += cost;
            Union(a, b);
        }
    }
    cout << ans;
    return 0;
}