#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int arr[2][a];
    for(int i = 0; i < a; i++){
        int b, c; cin >> b >> c;
        arr[i][0] = b;
        arr[i][1] = c;
    }
    int ans = 1;
    int flag = 0;
    while(1){
        int d;
        d = ans;
        flag = 0;
        for(int i = 0; i < a; i++){
            d *= 2;
            if(!(arr[i][0] <= d && d <= arr[i][1])){
                ans++;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            break;
        }
    }
    cout << ans;
    return 0;
}