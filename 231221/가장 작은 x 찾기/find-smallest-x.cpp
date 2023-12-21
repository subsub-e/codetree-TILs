#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int arr[a][2];
    for(int i = 0; i < a; i++){
        int b, c; cin >> b >> c;
        arr[i][0] = b;
        arr[i][1] = c;
    }
    int ans = 1;
    int d;
    while(1){
        d = ans;
        //cout << d << '\n';
        int flag = 0;
        for(int i = 0; i < a; i++){
            d = d * 2;
            if((d >= arr[i][0]) && (d <= arr[i][1])){
                flag = 1;
            }
            else{
                flag = 0;
                ans++;
                break;
            }
        }
        if(flag == 1){
            break;
        }
    }
    cout << ans;
    return 0;
}