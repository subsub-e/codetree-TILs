#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int uf[100001];

int find(int x){
    if(uf[x] == x){
        return x;
    }
    return uf[x] = find(uf[x]);
}

void Union(int x, int y){
    int x_par = find(x);
    int y_par = find(y);
    uf[x_par] = y_par;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        uf[i] = i;
    }

    while(m--){
        int x, a, b;
        cin >> x >> a >> b;
        if(x == 0){
            Union(a, b);
        }
        else{
            if(find(a) == find(b)){
                cout << 1 << '\n';
            }
            else{
                cout << 0 << '\n';
            }
        }
    }
    return 0;
}