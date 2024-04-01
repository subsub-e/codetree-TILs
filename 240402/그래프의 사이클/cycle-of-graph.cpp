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

bool Union(int a, int b){
    int pos_a = find(a);
    int pos_b = find(b);

    //cout << pos_a << ' ' << pos_b << '\n';

    if(pos_a == pos_b){
        return false;
    }
    else{
        arr[pos_a] = pos_b;
        return true;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        arr[i] = i;
    }
    // for(int i = 1; i <= n; i++){
    //     cout << arr[i] << ' ';
    // }
    // cout << '\n';
    for(int i = 1; i <= m; i++){
        int x1, x2;
        cin >> x1 >> x2;
        if(!Union(x1, x2)){
            cout << i;
            return 0;
        }
    }
    cout << "happy";
    return 0;
}