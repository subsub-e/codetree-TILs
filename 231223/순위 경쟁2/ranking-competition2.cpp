#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n; cin >> n;
    int arr[101][2];
    arr[0][0] = 0;
    arr[0][1] = 0;
    for(int i = 1; i <= n; i++){
        char c;
        int d; cin >> c >> d;
        if(c == 'A'){
            arr[i][0] = d;
            arr[i][1] = 0;
        }
        else{
            arr[i][0] = 0;
            arr[i][1] = d;
        }
    }
    int cnt = 0;
    for(int i = 1; i <=n; i++){
        int now = arr[i][1] - arr[i][0];
        int prev = arr[i-1][1] - arr[i-1][0];
        if((prev == 0 || prev < 0) && now > 0){
            cnt++;
        }
        else if((prev == 0 || prev > 0) && now < 0){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}