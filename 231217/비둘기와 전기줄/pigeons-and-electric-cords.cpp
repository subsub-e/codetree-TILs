#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int arr[11];
    for(int i = 0; i < 11; i++){
        arr[i] = 9;
    }
    int cnt = 0;
    for(int i = 0; i < a; i++){
        int b, c; cin >> b >> c;
        if(abs(arr[b] - c) == 1){
            cnt++;
        }
        arr[b] = c;
    }
    cout << cnt;
    return 0;
}