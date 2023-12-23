#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b; cin >> a >> b;
    int arr[a];
    for(int i = 0; i < a; i++){
        cin >> arr[i];
    }
    int cnt = 0;
    int idx;
    if(b == 0){
        for(int i = 0; i < a; i++){
            if(arr[i] == 1){
                cnt++;
            }
        }
        cout << cnt;
        return 0;
    }
    else if(b * 2 >= a){
        cout << 1;
        return 0;
    }
    else{
        for(int i = b; i < a; i++){
            if(arr[i - b] == 1){
                cnt++;
                idx = i;
                i += (b * 2 + 1);
            }
        }
        if(arr[idx + b + 1] == 1){
            cnt++;
        }
        cout << cnt;
    }
    
    return 0;
}