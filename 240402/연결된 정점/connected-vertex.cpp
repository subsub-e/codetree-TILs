#include <iostream>
using namespace std;


int arr[100001];
int sz[100001];
int n, m;

int find(int x){
    if(arr[x] == x){
        return x;
    }
    return arr[x] = find(arr[x]);
}

void Union(int a, int b){
    int pos_a = find(a);
    int pos_b = find(b);
    arr[pos_a] = pos_b;
    sz[pos_b] += sz[pos_a];
}



int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        arr[i] = i;
        sz[i] = 1;
    }

    for(int i = 0; i < m; i++){
        char c;
        cin >> c;
        if(c == 'x'){
            int x1, x2; cin >> x1 >> x2;
            Union(x1, x2);
        }
        else{
            int x1; cin >> x1;
            //memset(visited, 0, sizeof(visited));
            int size_x1 = find(x1);
            cout << sz[size_x1] << '\n';
        }
    }
    return 0;
}