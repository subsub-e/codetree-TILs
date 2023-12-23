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
        int flag = 0;
        for(int i = 0; i < a; i++){
            if(arr[i] == 1){
                flag = 1;
            }
        }
        if(flag == 0){
            cout << 0;
            return 0;
        }
        else{
            cout << 1;
            return 0;
        }
    }
    else{
        int i = b;
        while(i < a){
            //cout << i << '\n';
            if(arr[i - b] == 1){
                cnt++;
                idx = i;
                i += (b * 2 + 1);
            }
            else{
                i++;
            }
        }
        for(int i = (idx + b + 1); i < a; i++){
            if(arr[i] == 1){
                cnt++;
                break;
            }
        }
        cout << cnt;
    }
    
    return 0;
}