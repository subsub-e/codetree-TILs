#include <iostream>
#include <cmath>
#include <queue>
#include <unordered_map>
using namespace std;

int n, num;
int arr[1025];
int ans[1025];
int cnt = 1;
 
void inorder(int x){
    if(x > num){
        return;
    }

    inorder(x * 2);
    ans[x] = arr[cnt++];
    inorder(x * 2 + 1);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n; cin >> n;
    num = (1 << n) - 1;

    for(int i = 1; i <= num; i++){
        cin >> arr[i];
    }

    inorder(1);

    for(int i = 1; i <= n; i++){
        for(int j = (1 << (i - 1)); j <= (1 << i) - 1; j++){
            cout << ans[j] << ' ';
        }
        cout << '\n';
    }
}