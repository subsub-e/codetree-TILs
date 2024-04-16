#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n; cin >> n;
    int cnt = 0;
    for(int i = 0; i < n-1; i++){
        int x1, x2; cin >> x1 >> x2;
        if(x1 == 1){
            cnt++;
        }
    }
    if(cnt % 2 == 0){
        cout << 0;
    }
    else{
        cout << 1;
    }
    return 0;
}