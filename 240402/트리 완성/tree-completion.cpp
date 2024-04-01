#include <iostream>
using namespace std;

int arr[100001];
int n, m;

int find(int x){
    if(arr[x] == x){
        return x;
    }
    return arr[x] = find(arr[x]);
}

void Union(int a, int b){
    int pos_x = find(a);
    int pos_y = find(b);

    arr[pos_x] = pos_y;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        arr[i] = i;
    }

    for(int i = 0; i < m; i++){
        int x1, x2; cin >> x1 >> x2;
        Union(x1, x2);
    }

    int cnt = 0;
    for(int i = 2; i <= n; i++){
        if(find(i) != find(1)){
            cnt++;
            Union(1, i);
        }
    }
    cout << cnt;

    return 0;
}